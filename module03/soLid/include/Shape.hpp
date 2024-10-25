#pragma once

class Shape {
public:
  Shape() {}
  ~Shape() {}
  virtual int get_area() = 0;
  virtual int get_perimeter() = 0;
};
