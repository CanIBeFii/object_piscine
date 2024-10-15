#pragma once

#include <iostream>
#include <vector>
#include "Vector2.hpp"
#include <stdexcept>
#include <iomanip>

class Graph {
	private:
		Vector2 _size;
		std::vector<Vector2> _points;
	public:
		Graph();
		Graph(float x, float y);
		~Graph();

		Vector2 getSize();
		Vector2 getSize() const;

		void setSize(Vector2 newSize);

		void addPoint(Vector2 point);
		void removePoint(Vector2 point);
		bool isPoint(float y, float x);
		void printGraph();
};