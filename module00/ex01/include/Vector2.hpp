#pragma once

#include <iostream>

class Vector2 {
	private:
		float _x;
		float _y;
	public:
		Vector2();
		Vector2(float x, float y);
		~Vector2();

		bool operator==(const Vector2 vector);

		float getX();
		float getX() const;
		float getY();
		float getY() const;

};