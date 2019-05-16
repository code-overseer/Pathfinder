//
//  main.cpp
//  PathFinder
//
//  Created by Bryan Wong on 15/05/2019.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include "Obstacle.h"
#include "Vector3.hpp"
#include <string>
#include <nlohmann/json.hpp>
#include <unordered_map>
using namespace std;
using json = nlohmann::json;

int main(int argc, const char * argv[]) {
  string CODE_DIR = std::getenv("HOME");
  CODE_DIR += "/Documents/C++/PathFinder/PathFinder/TestCase.json";
  ifstream datafile(CODE_DIR);
  string data;
  datafile.seekg(0, ios::end);
  data.reserve(datafile.tellg());
  datafile.seekg(0, ios::beg);
  data.assign(istreambuf_iterator<char>(datafile), istreambuf_iterator<char>());
  datafile.close();
  
  list<Obstacle>* buildings = new list<Obstacle>();
  list<Obstacle>* nfz = new list<Obstacle>();
  json jso = json::parse(data);
  
  for (auto i = jso["Buildings"].begin(); i != jso["Buildings"].end(); i++) {
    buildings->push_back(Obstacle(*i));
  }
  for (auto i = jso["NFZs"].begin(); i != jso["NFZs"].end(); i++) {
    nfz->push_back(Obstacle(*i));
  }
  
  for (auto i = buildings->begin(); i != buildings->end(); i++) {
    cout << i->position.toString() << endl;
  }
  
  for (auto i = nfz->begin(); i != nfz->end(); i++) {
    cout << i->position.toString() << endl;
  }
  
  delete buildings;
  delete nfz;
  
  return 0;
}
