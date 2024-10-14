#include "Bank.hpp"
#include <iostream>

int main() {
	{
		Bank bank;

		std::cout << bank << std::endl;
	}
	{
		Bank bank(9000);

		bank.addAccount();
		bank.addAccount();
		bank.addAccount();
		std::cout << bank << std::endl;
	}
	{
		Bank bank(1000);

		bank.addAccount();
		bank.addAccount();

		bank.depositMoney(0, 1000);
		bank.depositMoney(1, 100);
		std::cout << bank << std::endl;
	}
	{
		Bank bank(1000);

		bank.addAccount();
		bank.addAccount();

		bank.depositMoney(0, 1000);
		bank.depositMoney(1, 100);
		bank.askForLoan(0, 1000);
		std::cout << bank << std::endl;
	}
	{
		try {
			Bank bank(1000);

			bank.addAccount();
			bank.addAccount();

			bank.depositMoney(0, 1000);
			bank.depositMoney(1, 100);
			bank.askForLoan(0, 950);
			// bank.askForLoan(0, 1000);
			// bank.deleteAccount(5);
			// bank.withdrawMoney(1, 100);
			bank.depositMoney(0, 999);
			std::cout << bank << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
    return 0;
}