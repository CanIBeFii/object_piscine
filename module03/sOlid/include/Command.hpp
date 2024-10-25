#pragma once

#include <iostream>
#include <string>
#include <vector>

class Command {
protected:
  int id;
  std::string date;
  std::string client;
  std::vector<std::pair<int, int>> articles;

public:
  Command(int id_, std::string date_, std::string client_)
      : id(id_), date(date_), client(client_) {
    std::cout << "COnstructor for Command called" << std::endl;
  }

  ~Command() { std::cout << "Destructor for Command called" << std::endl; }

  void add_article(int price, int quantity) {
    articles.push_back(std::pair<int, int>(price, quantity));
  }

  virtual int get_total_price() {
    int total = 0;
    for (std::vector<std::pair<int, int>>::iterator iter = articles.begin();
         iter != articles.end(); ++iter) {
      total += iter->first * iter->second;
    }
    return total;
  }
};
