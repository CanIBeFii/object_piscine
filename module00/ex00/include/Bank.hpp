#ifndef BANK_HPP
#define BANK_HPP

#include "Account.hpp"
#include <iostream>
#include <limits>
#include <map>
#include <stdexcept>

#define MAX_UNSIGNED_INT std::numeric_limits<unsigned int>::max()
#define MAX_DOUBLE std::numeric_limits<double>::max()

class Bank {
	private:
		class Account {
			public:
				Account();
				~Account();

				double getValue() const;
				double getLoan() const;

			private:
				double _value;
				double _loan;
		};
		static unsigned int _accountsIds;
		double _liquidity;
		std::map<int, Account *> _clientAccounts;
		
	public:
		Bank();
		Bank(int liquidity);
		Bank(const Bank& copy);
		~Bank();

		// Operators
		friend std::ostream& operator << (std::ostream& os, const Bank& bank);
		friend std::ostream& operator << (std::ostream& os, const Bank::Account* account);
		Bank& operator = (const Bank& copy);

		// Getters
		std::map<int, Account *>& getAllAccounts();
		std::map<int, Account *>& getAllAccounts() const;
		double getLiquidity();
		double getLiquidity() const;

		// Setter
		void setLiquidity(double amount) throw std::runtime_error;

		void addLiquidity(double amount) throw std::runtime_error;
		void addAccount() throw std::runtime_error;
		void deleteAccount(int accountId) throw std::runtime_error;

		void depositMoney(int accountId, double depositAmount);
		void withdrawMoney(int accountId, double withdrawAmount);
		void askForLoan(int accountId, double loanAmount);

}

#endif