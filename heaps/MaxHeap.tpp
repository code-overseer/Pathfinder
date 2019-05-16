#include "MaxHeap.hpp"
#include <functional>
using namespace std;

template<class T>
MaxHeap<T>::MaxHeap(function<int(T,T)> comparison) : AbstractHeap<T>(comparison) {};

template<class T>
bool MaxHeap<T>::_compare(T* e1, T* e2) const {
  return this->_comparer(*e1, *e2) >= 0;
}
