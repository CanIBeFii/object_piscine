#pragma once

#include "Shape.hpp"

class Circle : public Shape {
  int radius;

public:
  Circle() : radius(0) {}
  Circle(int radius_) : radius(radius_) {}
  ~Circle() {}
  int get_radius() { return radius; }
  void set_radius(int radius_) { radius = radius_; }
  int get_area() { return radius * radius * 3.1415; }
  int get_perimeter() { return radius * 2 * 3.1415; }
};
