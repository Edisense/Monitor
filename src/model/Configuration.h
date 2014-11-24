#include <map>
#include "Node.h"

class Configuration {

  std::map<int, Node> nodeTokenMapping;

public:

  // Publish this configuration to the sensor Nodes for use
  void publish();

  void assign(int token, Node node);


};