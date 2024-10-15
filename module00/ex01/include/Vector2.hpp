#pragma once

#include <iostream>

class Vector2 {
	private:
		float _x;
		float _y;
	public:
		Vector2();
		Vector2(float y, float x);
		~Vector2();

		bool operator==(const Vector2 vector);
		friend std::ostream& operator<<(std::ostream& os, const Vector2& vector);

		float getX();
		float getX() const;
		float getY();
		float getY() const;

};