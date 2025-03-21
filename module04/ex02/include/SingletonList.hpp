#pragma once

#include <memory>
#include <stdexcept>
#include <vector>

template <typename T> class SingletonList {
private:
  std::vector<std::shared_ptr<T>> _list;
  static std::unique_ptr<SingletonList> _instance_ptr;

  SingletonList() {}

public:
  ~SingletonList() {}
  SingletonList(const SingletonList &) = delete;
  SingletonList &operator=(const SingletonList) = delete;

  static SingletonList *get_instance() {
    if (_instance_ptr == nullptr) {
      _instance_ptr.reset(new SingletonList());
    }
    return _instance_ptr.get();
  }

  bool add_element(std::shared_ptr<T> element) {
    for (auto iter = _list.begin(); iter != _list.end(); ++iter) {
      if (*iter == element) {
        return false;
      }
    }
    _list.push_back(std::move(element));
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
  std::vector<std::shared_ptr<T>> &get_list() { return _list; }
  std::weak_ptr<T> operator[](int index) {
    if (index < 0 || index >= _list.size())
      throw std::out_of_range("Index is not in range of the list");
    return _list.at(index);
  }
};

template <typename T>
std::unique_ptr<SingletonList<T>> SingletonList<T>::_instance_ptr = nullptr;