#include <edisense_comms.h>
#include <edisense_types.h>
#include "client.h"

typedef struct {
  std::list<std::string> hostIDs;
} masterList_t;

class PollerDaemon {
public:
  void start(std::list<device_t> devices, std::string startHost);
  void stop();
protected:
  edisense_comms::Client *client;
  std::list<device_t> devices;
  std::map<std::string, std::list<device_t>> devsByHost;
  std::string knownHost;
private:
  bool shouldRun;
  void run();
  void relocate();  
};
