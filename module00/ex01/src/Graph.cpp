#include "Graph.hpp"

Graph::Graph(): _size(Vector2()), _points(std::vector<Vector2>()) {}

Graph::Graph(float x, float y): _size(Vector2(x, y)), _points(std::vector<Vector2>()) {}

Graph::~Graph() {}

Vector2& Graph::getSize() {
	return _size;
}

const Vector2& Graph::getSize() const {
	return _size;
}

void Graph::setSize(Vector2 newSize) {
	_size = newSize;
}

void Graph::addPoint(Vector2 point) {
	float x = point.getX();
	float y = point.getY();

	if (0 > x || x > _size.getX()) {
		std::cout << "Point doesnt fit inside the X size of Graph" << std::endl;
		return ;
	}
	if (0 > y || y > _size.getY()) {
		std::cout << "Point doesnt fit inside the Y size of Graph" << std::endl;
	}
	for (std::vector<Vector2>::iterator points_iterator = _points.begin();
		points_iterator != _points.end();
		++points_iterator)
		{
			if (point == *points_iterator) {
				std::cout << "Found a matching point in Graph already" << std::endl;
				return ;
			}
		}
	_points.push_back(point);
}

void Graph::removePoint(Vector2 point) {
	for (std::vector<Vector2>::iterator points_iterator = _points.begin();
		points_iterator != _points.end();
		++points_iterator)
		{
			if (point == *points_iterator) {
				_points.erase(points_iterator);
				return ;
			}
		}
	std::cout << "Didn't find any matching point in the Graph" << std::endl;
}

bool Graph::isPoint(float y, float x) {
	for (std::vector<Vector2>::iterator points_iterator = _points.begin();
		points_iterator != _points.end();
		++points_iterator)
		{
			if (points_iterator->getY() == y && points_iterator->getX() == x) {
				return true;
			}
		}
	return false;
}

std::ostream& operator<<(std::ostream& os, Graph& graph) {
	Vector2 graphSize = graph.getSize();
	for (int y = graphSize.getY(); y >= 0; y--){
		os << y;
		for (int x = 0; x <= graphSize.getX(); x++) {
			os << std::setw(3);
			if (graph.isPoint(y, x)) {
				os << "X";
			}
			else {
				os << ".";
			}
		}
		os << std::endl;
	}
	os << " ";
	for (int x = 0; x <= graphSize.getX(); x++) {
		os << std::setw(3) << x;
	}
	os << std::endl;
	return os;
}