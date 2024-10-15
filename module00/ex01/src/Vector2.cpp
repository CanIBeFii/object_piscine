#include "Vector2.hpp"

Vector2::Vector2(): _x(0), _y(0) {}

Vector2::Vector2(float x, float y): _x(x), _y(y) {}

Vector2::~Vector2() {}

bool Vector2::operator==(const Vector2 vector) {
	return _x == vector._x && _y == vector._y;
}

float Vector2::getX() {
	return _x;
}

float Vector2::getX() const {
	return _x;
}

float Vector2::getY() {
	return _y;
}

float Vector2::getY() const {
	return _y;
}
