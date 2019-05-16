#ifndef MinHeap_hpp
#define MinHeap_hpp

#include "AbstractHeap.hpp"
#include <functional>

template<class T>
struct MinHeap : public AbstractHeap<T> {
public:
  MinHeap(std::function<int(T,T)> comparison);
protected:
  bool _compare(T* e1, T* e2) const override;
};

#include "MinHeap.tpp"

#endif
