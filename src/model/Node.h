
class Node {

public:

  // Identifier for a given Node.  TODO MAC Address?
  std::string id();

  // Get the full set of sensor data for the provided time range
  // TODO abstract data somehow?
  std::list<int> getSensorData(int peripheralId, int startTime, int endTime);

};