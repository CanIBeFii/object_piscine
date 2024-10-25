#include "Command.hpp"
#include "PackageReductionDiscountCommand.hpp"
#include "TuesdayDiscountCommand.hpp"
#include <iostream>

int main() {
  Command simple(1, "Tuesday", "John Doe");

  simple.add_article(5, 10);
  std::cout << "Total price is: " << simple.get_total_price() << std::endl;
  simple.add_article(30, 2);
  std::cout << "Total price is: " << simple.get_total_price() << std::endl;

  TuesdayDiscountCommand tuesday(2, "Tuesday", "Jane Doe");
  tuesday.add_article(5, 10);
  std::cout << "Total price is: " << tuesday.get_total_price() << std::endl;
  tuesday.add_article(30, 2);
  std::cout << "Total price is: " << tuesday.get_total_price() << std::endl;

  TuesdayDiscountCommand not_tuesday(3, "Wednesday", "Peter Doe");
  not_tuesday.add_article(5, 10);
  std::cout << "Total price is: " << not_tuesday.get_total_price() << std::endl;
  not_tuesday.add_article(30, 2);
  std::cout << "Total price is: " << not_tuesday.get_total_price() << std::endl;

  PackageReductionDiscountCommand yipee(4, "Tuesday", "Jackson Doe");
  yipee.add_article(5, 10);
  std::cout << "Total price is: " << yipee.get_total_price() << std::endl;
  yipee.add_article(50, 2);
  std::cout << "Total price is: " << yipee.get_total_price() << std::endl;
  yipee.add_article(1, 1);
  std::cout << "Total price is: " << yipee.get_total_price() << std::endl;
  return 0;
}
