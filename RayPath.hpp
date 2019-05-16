#ifndef RayPath_hpp
#define RayPath_hpp

#include <iostream>
#include "Pathfinder.hpp"
#include <MinHeap.hpp>

class RayPath : public Pathfinder {
private:
  /* Data */
  float const _maxAlt = 150;
  float const _minAlt = 60;
  float const _altDiv = 10;
  float const _buildingDiv = 30;
  float const _Ra = 200;
  float const _Rd = 3;
  float const _epsilon = 0.001;
  float const hubAlt[2] = { 500, 510 };
  int const _altSize = (int)((_maxAlt - _minAlt)/_altDiv + 1);
  float* _altitudes = nullptr;
  int* _assigned = nullptr;
  int _droneCount;  
  Vector3* _origin = nullptr;
  Vector3* _destination = nullptr;
  
  /* Functions */
  static void _rotationY(float degree, Vector3& v);
  static Vector3 _getPerp(Vector3& v);
  
  int _countAtAltitude(int i, Vector3 dronePos[]);
  std::list<Vector3> _getRoute(Vector3 &org, Vector3 &dest, bool hubReturn);
  MinHeap<Obstacle> _blockers(Vector3 start, Vector3 end, float altitude);
  int _findIntersect(Obstacle obs, Vector3 start, Vector3 end, int i[2]);
  Vector3 _findAlternate(Obstacle obs, Vector3 start, Vector3 exclude);
  bool _isContained(Obstacle obs, Vector3 point);
  Vector3 _findWaypoint(Obstacle obs, Vector3 start, Vector3 end, int i[2]);
  std::list<Vector3> _navigate(Vector3 start, Vector3 end, float altitude);
public:
  ~RayPath();
  float const* altitudes();
  std::string getRoute(std::string const &raw) override;
  void updateGameState(Vector3 dronePos[], Obstacle nfzs[]);
  void chooseAltitude();
};

#endif /* RayPath_hpp */
