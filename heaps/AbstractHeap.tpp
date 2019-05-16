#include "AbstractHeap.hpp"
#include <exception>
using namespace std;
template<class T>
AbstractHeap<T>::AbstractHeap(function<int(T,T)> comparison) {
	_comparer = comparison;
  _count = 0;
  _capacity = INITIAL_CAP;
	_data = new T* [_capacity];
  for (int i = 0; i < _capacity; i++) {
    _data[i] = nullptr;
  }
}

template<class T>
AbstractHeap<T>::~AbstractHeap() {

  for (int i = 0; i < _count; i++){
		if (_data[i]) delete _data[i];
  }

	if (_data) delete [] _data;
}
template<class T>
int AbstractHeap<T>::getCount() const{
	return _count;
}

template<class T>
int AbstractHeap<T>::getCapacity() const{
	return _capacity;
}

template<class T>
bool AbstractHeap<T>::isEmpty() const {
  return _count == 0;
}

template<class T>
void AbstractHeap<T>::clear() {
	_count = 0;
	_capacity = INITIAL_CAP;
	for (int i = 0; i <_capacity; i++)
		if (_data[i]) delete _data[i];
	delete [] _data;
	_data = new T* [_capacity];
  for (int i = 0; i < _capacity; i++) {
    _data[i] = nullptr;
  }
}

template<class T>
void AbstractHeap<T>::add(T element) {
  if (_count == _capacity - 1) {
    _doubleSize();
  }
  int pos = ++_count;
  if (_comparer) {
    while (pos > 1 && _compare(&element, _data[pos / 2])) {
      _data[pos] = _data[pos / 2];
      pos /= 2;
    }
  }
  T* input = new T;
  *input = element;
  _data[pos] = input;
}

template<class T>
T AbstractHeap<T>::remove() {
	if (isEmpty()) { 
		throw runtime_error("Heap is empty");
	}
  T output;
	if (_comparer) {
		output = *_data[1];
    delete _data[1];
		int n = 1;
		for (; 2 * n < _count && !_compare(_data[_count],
			_data[_nextChildIndex(n)]); n = _nextChildIndex(n)) {
			_data[n] = _data[_nextChildIndex(n)];
		}
    _data[n] = _data[_count];
	} else {
		output = *_data[_count];
	}
  _data[_count--] = nullptr;
	return output;
}

template<class T>
T& AbstractHeap<T>::peek() const {
	if (isEmpty()) { 
		throw runtime_error("Heap is empty");
	}
	return *_data[1];
}

template<class T>
void AbstractHeap<T>::_doubleSize() {
	_capacity *= 2;
	T** tmp = new T*[_capacity];
  tmp[0] = nullptr;
	for (int i = 1; i <= _count; i++) {
		tmp[i] = _data[i];
	}
  for (int i = _count + 1; i < _capacity; i++) {
    tmp[i] = nullptr;
  }
	delete [] _data;
	_data = tmp;
}

template<class T>
int AbstractHeap<T>::_nextChildIndex(int n) const {
	int m = 2 * n;
	if (!_compare(_data[m], _data[m + 1]))
		m++;

	return m;
}

template<class T>
void AbstractHeap<T>::heapify(int i)
{
  int extreme = i; // Initialize largest as root
  int l = 2 * i; // left = 2*i + 1
  int r = 2 * i + 1; // right = 2*i + 2
  
  // If left child is larger than root
  if (l <= getCount() && _compare(_data[l], _data[extreme]))
  {
    extreme = l;
  }
  
  // If right child is larger than largest so far
  if (r <= getCount() && _compare(_data[r], _data[extreme]))
  {
    extreme = r;
  }
  
  // If largest is not root
  if (extreme != i)
  {
    swap<T>(_data[i], _data[extreme]);
    // Recursively heapify the affected sub-tree
    heapify(extreme);
  }
}
