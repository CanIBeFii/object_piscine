#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>
#include <map>

class Vector2 {
	private:
		float _x;
		float _y;
	public:
		Vector2();
		Vector2(float x, float y);
		~Vector2();

		float getX();
		float getX() const;
		float getY();
		float getY() const;

};

#endif