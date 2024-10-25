#pragma once

#include "Command.hpp"
#include <iostream>

class PackageReductionDiscountCommand : public Command {
public:
  PackageReductionDiscountCommand(int id_, std::string date_,
                                  std::string client_)
      : Command(id_, date_, client_) {
    std::cout << "Constructor for PackageReductionDiscountCommand called"
              << std::endl;
  }

  ~PackageReductionDiscountCommand() {
    std::cout << "Destructor for PackageReductionDiscountCommand called"
              << std::endl;
  }

  int get_total_price() {
    int total = 0;
    for (std::vector<std::pair<int, int> >::iterator iter = articles.begin();
         iter != articles.end(); ++iter) {
      total += iter->first * iter->second;
    }
    if (total > 150) {
      return total * 0.9;
    }
    return total;
  }
};
