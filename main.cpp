#include <iostream>
#include <chrono>
#include <QtWidgets/qapplication.h>
#include <HomeController.h>
#include "PollerDaemon.h"

using namespace std;

int main(int argc, char *argv[]) {

  std::cout << "Monitor Test ******* " << std::endl;
  PollerDaemon poll_d;
  std::list<device_t> devices;
  int dev_id_start = 1;
  int dev_id_max = 50;
  for (int i = dev_id_start; i < dev_id_max; ++i)
    devices.push_back(i);
  poll_d.start(devices, "corn34.stanford.edu");
  volatile  int i = 0;
  while(1)
    {
      ++i;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }

  QApplication app(argc, argv);
  HomeController* appController = new HomeController;
  appController->start();
  return app.exec();
}
