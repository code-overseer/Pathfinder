#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include<iostream>
#include<functional>

template<class T>
struct AbstractHeap {
public:
  /* Functions */
  void add(T element);
  T remove();
  void clear();
  T& peek() const;
  int getCount() const;
  int getCapacity() const;
  bool isEmpty() const;
  AbstractHeap(std::function<int(T,T)> comparison);
  virtual ~AbstractHeap();
protected:
  /* Fields */
  std::function<int (T,T)> _comparer = NULL; // stores the lambda
  /* Functions */
  virtual bool _compare(T* e1, T* e2) const = 0;
private:
  static int const INITIAL_CAP = 10;
  T** _data;
  int _count, _capacity;
  int _nextChildIndex(int n) const;
  void _doubleSize();
  void heapify(int i);
  
};
#include "AbstractHeap.tpp"
#endif
