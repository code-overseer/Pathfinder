#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include "AbstractHeap.hpp"

template<class T>
struct MaxHeap : public AbstractHeap<T> {
public:
  MaxHeap(std::function<int(T,T)> comparison) : AbstractHeap<T>(comparison) {};
protected:
  bool _compare(T* e1, T* e2) const override {
    return this->_comparer(*e1, *e2) >= 0;
  }
};

#endif
