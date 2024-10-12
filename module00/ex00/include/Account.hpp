#pragma once

#include <iostream>
#include <vector>

class Account {
	private:
		int _id;
		int _value;

	public:
		Account();
		~Account();

		int getId();
		int getValue();

		friend std::ostream& operator << (std::ostream, const Account& account);
		