#include <chrono>
#include <thread>
#include "PollerDaemon.h"

void PollerDaemon::start(std::list<device_t> devices) {
  client = new edisense_comms::Client();

}

void PollerDaemon::stop() {
  shouldRun = false;
}

void PollerDaemon::run() {
  while (shouldRun) {

    client->get(<#(transaction_t)tid#>, <#(list<string> &)recipients#>, <#(device_t)deviceId#>, <#(time_t)begin#>, <#(time_t)end#>)


    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

}
