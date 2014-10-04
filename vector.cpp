#include <iostream>
#include <iterator>

template <typename T> 
void swap(T &a, T &b) {
  T c = b;
  b = a;
  a = c; 
}

struct vector_t {
  int *ptr; // pointer
  int _capacity;
  int _size;

  void init() {
    ptr = NULL;
    _capacity = 0;
    _size = 0;
  }

  void init(int sz) {
    ptr = new int[sz];
    _capacity = sz;
    _size = 0;
  }

  void resize(int sz) {
    int *new_ptr = new int[sz];
    int i = 0;
    for (; i < sz && i < _size; ++i) {
      new_ptr[i] = ptr[i];
    }
    swap(ptr, new_ptr);
    swap(_capacity, sz);
    delete [] new_ptr;
  }

  void free() {
    delete [] ptr;
    // delete ptr;
    _capacity = 0;
    _size = 0;
  }
  int & operator[] (int id) {
    std::cout << ".";
    return ptr[id];
  }
  const int & operator[] (int id) const {
    std::cout << ",";
    return ptr[id];
  }

  void append(int value) {
    if (_size == _capacity) {
      resize(_capacity * 2);
    }
    ptr[_size] = value;
    ++_size;
  }

  int size() const {
    return _capacity;
  }

  void print() const {
    std::cout << "[";
    std::copy(ptr, ptr+_capacity, std::ostream_iterator<int>(std::cout," "));
    std::cout << "]";
    std::cout << std::endl;
  }
};


int main() {

  vector_t a;

  a.init(2);
   
  const int max_capacity = 10;
  //a[0] = 1;
  //a[1] = 1;
  a.append(1);
  a.append(1);
  for (int i = 2; i < max_capacity; ++i) {
    int value = a[i - 1] + a[i - 2];
    a.print();
    a.append(value);
  }

  const vector_t &b = a;
  for (int i = 0; i < a.size(); ++i) {
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  a.free();

  return 0;
}
