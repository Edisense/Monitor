#include <chrono>
#include <thread>
#include <map>
#include <iostream>
#include <cassert>
#include "PollerDaemon.h"

void PollerDaemon::start(std::list<device_t> devices, std::string startHost) {
  client = new edisense_comms::Client();
  this->devices = devices;
  this->knownHost = startHost; //We have to have at least one known host to query the master list
  relocate();
  run();
}

void PollerDaemon::stop() {
  shouldRun = false;
}

void PollerDaemon::relocate() {
  std::map<device_t, std::list<std::string>> hostsByDev;
  devsByHost.clear(); //reset the master list
  for(std::list<device_t>::iterator it = devices.begin(); it != devices.end(); ++it) {
    std::future<std::list<std::string>> hostIDs = client->locate(*it, knownHost);
    std::future_status status = hostIDs.wait_for(std::chrono::seconds(2));

    std::cout << "Give me all hosts that store device: " << *it << ". Asking: " << knownHost << std::endl;

    assert(std::future_status::ready == status);
    std::list<std::string> results = hostIDs.get();
    //Any reason to not always use knownHost?
    hostsByDev.insert(std::pair<device_t, std::list<std::string>>(*it, results));
  }
  for(std::map<device_t, std::list<std::string>>::iterator it = hostsByDev.begin(); it != hostsByDev.end(); ++it) {
    for(std::list<std::string>::iterator iit = it->second.begin(); iit != it->second.end(); ++iit) {
      auto search = devsByHost.find(*iit);
      if(search == devsByHost.end()) {
        //not found
        std::list<device_t> tempDevList;
        tempDevList.push_back(it->first);
        devsByHost.insert(std::pair<std::string, std::list<device_t>>(*iit, tempDevList));
      }
      else {
        search->second.push_back(it->first);
	search->second.sort();
	search->second.unique(); //remove duplicates
      }
    }
  }
}

void PollerDaemon::run() {
  uint32_t tid = 0;
  const uint32_t QUERY_WINDOW = 10; //in seconds
  time_t startT = 0;
  time_t endT = 0;
  bool relocate_f = false;
  std::future<std::list<GetResult>> resultData;
  while (shouldRun) {
    time(&endT);
    startT = endT - QUERY_WINDOW;

    for (std::map<std::string, std::list<device_t>>::iterator it = devsByHost.begin(); it != devsByHost.end(); ++it) {
      std::list<std::string> tempHost;
      tempHost.push_back(it->first);

      std::cout << std::endl;

      for (std::list<device_t>::iterator iit = it->second.begin(); iit != it->second.end(); iit++) {
        resultData = client->get(++tid, tempHost, *iit, startT, endT);
	std::future_status status = resultData.wait_for(std::chrono::seconds(2));
	assert(std::future_status::ready == status);
	std::list<GetResult> results = resultData.get();
	assert(1 == results.size());
        //do something with the data
	if (results.begin()->status == SUCCESS) {
          std::list<Data> readings = *results.begin()->values;
          for (std::list<Data>::iterator j = readings.begin(); j != readings.end(); j++) {
	    long long* temp_data = reinterpret_cast<long long*>(&j->data[0]);
            std::cout << "host: " << it->first << " | device: " << *iit << " | data: " << *temp_data << std::endl;
	  }
	}
        else {
          //we need to locate the nodes again and rebuild the master list
          relocate_f = true;
	}
      }
    }
    if(relocate_f) {
      relocate();
      relocate_f = false;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

}
