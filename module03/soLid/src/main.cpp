#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <ostream>
#include <vector>

int main() {
  std::vector<Shape *> shapes;

  Rectangle rectangle(2, 5);
  Circle circle(10);
  Triangle triangle(2, 4, 4, 5);

  shapes.push_back(&rectangle);
  shapes.push_back(&circle);
  shapes.push_back(&triangle);

  for (std::vector<Shape *>::iterator iter = shapes.begin();
       iter != shapes.end(); ++iter) {
    std::cout << "The shape area is: " << (*iter)->get_area() << std::endl;
    std::cout << "The shape perimeter is: " << (*iter)->get_perimeter()
              << std::endl
              << std::endl;
  }
  return 0;
}
