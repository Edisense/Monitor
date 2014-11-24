#include "HomeView.h"

class HomeController {
HomeView* homeView;
public:
  HomeController();
  void start();

  void changeTokenNodeAssociation(int token, Node node);

};
