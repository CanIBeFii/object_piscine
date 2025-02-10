#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename T> class SingletonList {
private:
  std::vector<T *> _list;
  static SingletonList *_instance_ptr;

  SingletonList() {}

public:
  ~SingletonList() {}
  SingletonList(const SingletonList &) = delete;
  SingletonList &operator=(const SingletonList) = delete;

  static SingletonList *get_instance() {
    if (_instance_ptr == nullptr) {
      _instance_ptr = new SingletonList();
    }
    return _instance_ptr;
  }

  bool add_element(T *element) {
    for (auto iter = _list.begin(); iter != _list.end(); ++iter) {
      if (*iter == element) {
        return false;
      }
    }
    _list.push_back(element);
    return true;
  }
  bool delete_element(T *element) {
    for (auto iter = _list.begin(); iter != _list.end(); ++iter) {
      if (*iter == element) {
        _list.erase(iter);
        return true;
      }
    }
    return false;
  }
  std::vector<T *> &get_list() { return _list; }
  T *operator[](int index) {
    if (index < 0 || index >= _list.size())
      throw std::out_of_range("Index is not in range of the list");
    return _list.at(index);
  }
};

template <typename T>
SingletonList<T> *SingletonList<T>::_instance_ptr = nullptr;