#ifndef PathFinder_hpp
#define PathFinder_hpp

#include "Obstacle.h"
#include <list>
#include <string>
#include <nlohmann/json.hpp>

class Obstacle;

class Pathfinder {
public:
  virtual ~Pathfinder();
protected:
  std::list<Obstacle*>* buildings = nullptr;
  std::list<Obstacle*>* noFlyZones = nullptr;
  
  void loadBuildings(std::string filename);
  
  virtual std::string getRoute(std::string const &data) = 0;
  
private:
  void parseBuildingData(std::string const &data);
};

#endif /* PathFinder_hpp */
