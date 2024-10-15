#include "Graph.hpp"
#include "Vector2.hpp"

int main() {
	{
		Vector2 vector;
		std::cout << vector << std::endl;
	}
	{
		Vector2 vector(2, 3);
		std::cout << vector << std::endl;
	}
	{
		Graph graph;
		std::cout << graph << std::endl;
	}
	{
		Graph graph(5, 6);
		std::cout << graph << std::endl;
	}
	{
		Graph graph(5, 6);

		graph.addPoint(Vector2(5, 5));
		graph.addPoint(Vector2(2, 4));
		graph.addPoint(Vector2(0, 1));
		graph.addPoint(Vector2(5, 6));
		graph.addPoint(Vector2(0, 0));
		std::cout << graph << std::endl;
	}
	{
		Graph graph(5, 6);

		graph.addPoint(Vector2(5, 5));
		graph.addPoint(Vector2(2, 4));
		graph.addPoint(Vector2(0, 1));
		std::cout << graph << std::endl;
		graph.removePoint(Vector2(0, 0));
		graph.addPoint(Vector2(6, 6));
		graph.removePoint(Vector2(0, 1));
		graph.removePoint(Vector2(5, 5));
		std::cout << graph << std::endl;
	}
}