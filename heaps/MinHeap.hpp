#ifndef MinHeap_hpp
#define MinHeap_hpp

#include "AbstractHeap.hpp"

template<class T>
struct MinHeap : public AbstractHeap<T> {
public:
  MinHeap(std::function<int(T,T)> comparison) : AbstractHeap<T>(comparison) {};
protected:
  bool _compare(T* e1, T* e2) const override {
    return this->_comparer(*e1, *e2) <= 0;
  }
};

#endif
