#pragma once

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"
#include <set>

class Tool;

class Worker {
	private:
		Position coordonnee;
		Statistic stat;
		std::set<Tool*> tools;
	public:
		Worker();
		Worker(Position coord, Statistic statistic);
		Worker(const Worker& copy);
		~Worker();

		Position& getCoordonnee();
		Statistic& getStat();

		void assignTool(Tool* new_tool);
		void removeTool(Tool* tool);
		void useTool(Tool* tool);

		template<typename T>
		T* getTool() {
			for (std::set<Tool*>::iterator iter = tools.begin();
				iter != tools.end();
				++iter)
				{
					if (T* tool = dynamic_cast<T*>(*iter)) {
						return *iter;
					}
				}
		}

		friend class Shovel;
};