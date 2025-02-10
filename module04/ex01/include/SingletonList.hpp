#pragma once

#include <stdexcept>
#include <vector>

template <typename T> class SingletonList {
private:
  std::vector<T *> _list;
  static SingletonList *_instance_ptr = nullptr;

  SingletonList() {}
  ~SingletonList() {}

public:
  SingletonList(const SingletonList &) = delete;
  SingletonList &operator=(const SingletonList) = delete;

  static SingletonList *getInstance() {
    if (_instance_ptr == nullptr) {
      _instance_ptr = new SingletonList();
    }
    return _instance_ptr;
  }

  void add_element(T *element) { _list.push_back(element); }
  bool delete_element(T *element) {
    for (typename std::vector<T *>::iterator iter = _list.begin();
         iter != _list.end(); ++iter) {
      if (element == *iter) {
        _list.erase(iter);
        return true;
      }
    }
    return false;
  }
  std::vector<T *> get_list() { return _list; }
  T *operator[](int index) {
    if (index < 0 || index >= _list.size())
      throw std::out_of_range("Index is not in range of the list");
    return _list.at(index);
  }
};