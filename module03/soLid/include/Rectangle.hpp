#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
  int width;
  int height;

public:
  Rectangle() : width(0), height(0) {}
  Rectangle(int width_, int height_) : width(width_), height(height_) {}
  ~Rectangle() {}
  int get_width() { return width; }
  int get_height() { return height; }
  void set_height(int height_) { height = height_; }
  void set_width(int width_) { width = width_; }
  int get_area() { return width * height; }
  int get_perimeter() { return width * 2 + height * 2; }
};
