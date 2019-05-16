#include "Pathfinder.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

void Pathfinder::parseBuildingData(std::string const &data) {
  buildings = new list<Obstacle>();
  json jso = json::parse(data);
  
  for (auto i = jso["Buildings"].begin(); i != jso["Buildings"].end(); i++) {
    buildings->push_back(Obstacle(*i));
  }
}

void Pathfinder::loadBuildings(string filename) {
  ifstream datafile(filename);
  string data;
  datafile.seekg(0, ios::end);
  data.reserve(datafile.tellg());
  datafile.seekg(0, ios::beg);
  data.assign(istreambuf_iterator<char>(datafile), istreambuf_iterator<char>());
  datafile.close();
  
  parseBuildingData(data);
}

Pathfinder::~Pathfinder() {
  if (buildings)
    delete buildings;
  if (noFlyZones)
    delete noFlyZones;
}
