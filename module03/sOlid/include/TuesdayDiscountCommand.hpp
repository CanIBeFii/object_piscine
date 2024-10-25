#pragma once

#include "Command.hpp"

class TuesdayDiscountCommand : public Command {
public:
  TuesdayDiscountCommand(int id_, std::string date_, std::string client_)
      : Command(id_, date_, client_) {
    std::cout << "Constructor for TuesdayDiscountCommand called" << std::endl;
  }

  ~TuesdayDiscountCommand() {
    std::cout << "Destructor for TuesdayDiscountCommand called" << std::endl;
  }

  int get_total_price() {
    int total = 0;
    for (std::vector<std::pair<int, int> >::iterator iter = articles.begin();
         iter != articles.end(); ++iter) {
      total += iter->first * iter->second;
    }
    if (date == "Tuesday") {
      return total * 0.9;
    }
    return total;
  }
};
