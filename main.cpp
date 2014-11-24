#include <iostream>
#include <QtWidgets/qapplication.h>
#include <HomeController.h>

using namespace std;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  HomeController* appController = new HomeController;
  appController->start();
  return app.exec();
}