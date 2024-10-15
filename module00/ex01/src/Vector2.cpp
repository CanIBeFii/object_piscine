#include "Vector2.hpp"

Vector2::Vector2(): _x(0), _y(0) {}

Vector2::Vector2(float y, float x): _x(x), _y(y) {}

Vector2::~Vector2() {}

bool Vector2::operator==(const Vector2 vector) {
	return _x == vector._x && _y == vector._y;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vector) {
	os << "Vector: y->" << vector._y << " x->" << vector._x << std::endl;
	return os;
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
