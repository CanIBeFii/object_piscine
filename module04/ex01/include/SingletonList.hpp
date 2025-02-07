#pragma once

#include <vector>

template <typename T> class SingletonList {
private:
  std::vector<T> m_list;
  static SingletonList *instance_ptr = nullptr;

  SingletonList() {}
  ~SingletonList() {}

public:
  SingletonList(const SingletonList &) = delete;
  SingletonList &operator=(const SingletonList) = delete;

  SingletonList *getInstance() {
    if (instance_ptr == nullptr) {
    }
  }
};