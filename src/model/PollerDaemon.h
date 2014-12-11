#include <edisense_comms.h>
#include <edisense_types.h>

class PollerDaemon {
public:
  void start(std::list<device_t> devices);
  void stop();
protected:
  edisense_comms::Client *client;
  std::list<device_t> devices;
private:
  bool shouldRun;
  void run();

};