#include <QtWidgets/qmainwindow.h>
#include <Node.h>
#include "ui_Edisense.h"

class HomeView : public QMainWindow, private Ui::MainWindow {
Q_OBJECT
public:
  HomeView();

  void setNodeList(std::list<Node> nodes);
};