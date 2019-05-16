#include "RayPath.hpp"
#include <cmath>
using namespace std;

void RayPath::_rotationY(float degree, Vector3& v) {
  float rad = degree * M_PI / 180;
  float cos_t = cos(rad);
  float sin_t = sin(rad);
  
  v.x = v.x * cos_t + v.z * sin_t;
  v.z = v.x * -sin_t + v.z * cos_t;
}

Vector3 RayPath::_getPerp(Vector3 &v) {
  auto out = v;
  _rotationY(90, out);
  return out;
}

float const* RayPath::altitudes() {
  if (!_altitudes) {
    _altitudes = new float[_altSize];
    _assigned = new int[_altSize];
    for (int i = 0; i < _altSize; i++) {
      _altitudes[i] = _minAlt + i * _altDiv;
      _assigned[i] = 0;
    }
  }
  return _altitudes;
}


