#pragma once

#include <iostream>
#include <string>
#include <vector>

class Command {
	int	id;
	int	date; // TODO implement using correct date class maybe
	std::string	client;
	std::vector<std::pair<int, int>>	articles;

	public:
		Command() {
			std::cout << "COnstructor for Command called" << std::endl;
		}

		~Command() {
			std::cout << "Destructor for Command called" << std::endl;
		}

		int	get_total_price() {
			int total = 0;
			for (std::vector<std::pair<int, int>>::iterator iter = articles.begin();
				iter != articles.end();
				++iter)
			{
				total += iter->first * iter->second;
			}
			return total;
		}
};
