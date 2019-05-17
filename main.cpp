#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <string>
#include <nlohmann/json.hpp>
#include "Obstacle.h"
#include "Vector3.hpp"
#include "RayPath.hpp"
#include <time.h>

using namespace std;
using json = nlohmann::json;

int main(int argc, const char * argv[]) {
  clock_t T = 0;
  int n = 100;
  string CODE_DIR = std::getenv("HOME");
  CODE_DIR += "/Documents/C++/PathFinder/PathFinder/TestCase.json";
  ifstream datafile(CODE_DIR);
  string data;
  datafile.seekg(0, ios::end);
  data.reserve(datafile.tellg());
  datafile.seekg(0, ios::beg);
  data.assign(istreambuf_iterator<char>(datafile), istreambuf_iterator<char>());
  datafile.close();
  
  RayPath pathfinder(CODE_DIR);
  for (int i = 0; i < n; i++) {
    clock_t t = clock();
    cout << pathfinder.getRoute(data) << endl;
    t = clock() - t;
    T += t;
  }
  
  cout<<"time: " << ((float) T/n)/CLOCKS_PER_SEC<< " seconds"<<endl;
  
  return 0;
}
