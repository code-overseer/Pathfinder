#include "Pathfinder.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

void Pathfinder::parseBuildingData(std::string const &data) {
  buildings = new list<Obstacle*>();
  json jso = json::parse(data);
  
  for (auto i = jso["Buildings"].begin(); i != jso["Buildings"].end(); i++) {
    buildings->push_back(new Obstacle(*i));
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
  if (buildings) {
    for (auto i = buildings->begin(); i != buildings->end(); i++) {
      delete *i;
    }
    delete buildings;
  }
  if (noFlyZones) {
    for (auto i = noFlyZones->begin(); i != noFlyZones->end(); i++) {
      delete *i;
    }
    delete noFlyZones;
  }
}
