#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include "AbstractHeap.hpp"
#include <functional>

template<class T>
struct MaxHeap : public AbstractHeap<T> {
public:
  MaxHeap(std::function<int(T,T)> comparison);
protected:
  bool _compare(T* e1, T* e2) const override;
};

#include "MaxHeap.tpp"

#endif
