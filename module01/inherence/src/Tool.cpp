#include "Tool.hpp"

Tool::Tool(): number_of_uses(0) {
	std::cout << "Tool default constructor called" << std::endl;
}

Tool::Tool(int uses): number_of_uses(uses) {
	std::cout << "Tool constructor called with uses: " << uses << std::endl;
}

Tool::Tool(const Tool& copy): number_of_uses(copy.number_of_uses) {
	std::cout << "Tool copy coonstructor called" << std::endl;
	current_worker = copy.current_worker;
}

Tool::~Tool() {
	std::cout << "Tool destructor called" << std::endl;
}

int Tool::getNumberOsUses() {
	return number_of_uses;
}

void Tool::leaveWorker() {
	if (current_worker != NULL) {
		current_worker->removeTool(this);
		current_worker = NULL;
	}
}