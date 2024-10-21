#pragma once

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"
#include <set>

class Tool;
class Workshop;
class Worker {
	private:
		Position coordonnee;
		Statistic stat;
		std::set<Tool*> tools;
		std::set<Workshop*> workshops;

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
		
		void joinWorkshop(Workshop* workshop);
		void removeWorkshop(Workshop* workshop);
		void leaveWorkshop(Workshop* workshop);
		void work(Workshop* workshop);

		template<typename T>
		T* getTool() {
			for (std::set<Tool*>::iterator iter = tools.begin();
				iter != tools.end();
				++iter)
				{
					T* tool = dynamic_cast<T*>(*iter);
					if (tool != NULL) {
						return tool;
					}
				}
				return NULL;
		};

		friend class Tool;
		friend class Workshop;
};

