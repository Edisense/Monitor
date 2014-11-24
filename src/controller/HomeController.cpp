#include "HomeController.h"

HomeController::HomeController() {
  this->homeView = new HomeView;
}

void HomeController::start() {
  this->homeView->show();
}


