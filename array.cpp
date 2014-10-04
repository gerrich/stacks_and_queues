#include <iostream>

template <typename T> 
void swap(T &a, T &b) {
  T c = b;
  b = a;
  a = c; 
}

struct array_t {
  int *ptr; // pointer
  int _size;

  void init() {
    ptr = NULL;
    _size = 0;
  }

  void init(int sz) {
    ptr = new int[sz];
    _size = sz;
  }

  void resize(int sz) {
    int *new_ptr = new int[sz];
    int i = 0;
    for (; i < sz && i < _size; ++i) {
      new_ptr[i] = ptr[i];
    }
    for (; i < sz; ++i) {
      new_ptr[i] = 0; 
    }
    swap(ptr, new_ptr);
    swap(_size, sz);
    delete [] new_ptr;
  }

  void free() {
    delete [] ptr;
    // delete ptr;
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
    int old__size = _size;
    resize(_size + 1);
    ptr[old__size] = value;
  }

  int size() const {
    return _size;
  }
};


int main() {

  array_t a;

  a.init(2);
   
  const int max_size = 10;
  a[0] = 1;
  a[1] = 1; 
  for (int i = 2; i < max_size; ++i) {
    int value = a[i - 1] + a[i - 2];
    a.append(value);
  }

  const array_t &b = a;
  for (int i = 0; i < a.size(); ++i) {
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  a.free();

  return 0;
}
