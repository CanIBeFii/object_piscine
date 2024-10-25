#pragma once

#include "Shape.hpp"

class Triangle : public Shape {
  int a;
  int b;
  int c;
  int height;
  // The objective is not being accurate
  // so i ain't doing all the calculations to get height and all that
  // going to assume a is the base always
public:
  Triangle() : a(0), b(0), c(0), height(0) {}
  Triangle(int a_, int b_, int c_, int height_)
      : a(a_), b(b_), c(c_), height(height_) {}
  ~Triangle() {}
  int get_a() { return a; }
  int get_b() { return b; }
  int get_c() { return c; }
  void set_a(int a_) { a = a_; }
  void set_b(int b_) { b = b_; }
  void set_c(int c_) { c = c_; }
  void set_height(int height_) { height = height_; }
  int get_area() { return a * height / 2; }
  int get_perimeter() { return a + b + c; }
};
