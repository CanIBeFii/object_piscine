#ifndef BANK_HPP
#define BANK_HPP

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

				friend class Bank;

			private:
				double _value;
				double _loan;
		};
		static unsigned int _accountsIds;
		double _liquidity;
		std::map<int, Account *> _clientAccounts;

		void addMoneyToAccount(Account* account, double amount);
		
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
		std::map<int, Bank::Account *>& getAllAccounts();
		double getLiquidity();
		double getLiquidity() const;

		// Setter
		void setLiquidity(double amount);

		void addLiquidity(double amount);
		void addAccount();
		void deleteAccount(int accountId);

		void depositMoney(int accountId, double depositAmount);
		void withdrawMoney(int accountId, double withdrawAmount);
		void askForLoan(int accountId, double loanAmount);

};

#endif