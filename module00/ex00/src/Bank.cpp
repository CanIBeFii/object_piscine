#include "Bank.hpp"

unsigned int Bank::_accountsIds = 0;

Bank::Bank(): _liquidity(0) {}

Bank::Bank(int liquidity): _liquidity(liquidity) {}

Bank::Bank(const Bank& copy): _liquidity(copy._liquidity) {
	_clientAccounts.insert(copy._clientAccounts.begin(), copy._clientAccounts.end());
}

Bank& Bank::operator = (const Bank& copy) {
	if (this != &copy) {
		_liquidity = copy._liquidity;
		_clientAccounts.insert(copy._clientAccounts.begin(), copy._clientAccounts.end());
	}
	return *this;
}

Bank::~Bank() {
	for (std::map<int, Account *>::iterator iter = _clientAccounts.begin();
		iter != _clientAccounts.end();
		++iter) {
			delete iter->second;
		}
}

std::ostream& operator<<(std::ostream& os, Bank& bank) {
	os << "Bank -> [" << std::endl;
	os << "\tLiquidity: " << bank._liquidity << std::endl;
	os << "\tAccounts: [" << std::endl;
	std::map<int, Bank::Account*> allAccounts = bank.getAllAccounts();
	for (std::map<int, Bank::Account*>::iterator iter = allAccounts.begin();
		iter != allAccounts.end();
		++iter) {
			os << "\t\tAccount " << iter->first << " " << iter->second << std::endl;
		}
	os << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bank::Account* account) {
	os << "[Money: " << account->getMoney();
	os << " Loan: " << account->getLoan() << "]";
}

Bank::Account* Bank::operator[](int accountId) {
	std::map<int, Bank::Account*>::iterator account = _clientAccounts.find(accountId);
	if (account == _clientAccounts.end()) {
		throw std::runtime_error("There's no such account with that id :(");
	}
	return account->second;
}

std::map<int, Bank::Account *>& Bank::getAllAccounts() {
	return _clientAccounts;
}

double Bank::getLiquidity() {
	return _liquidity;
}

double Bank::getLiquidity() const {
	return _liquidity;
}

void Bank::setLiquidity(double amount) {
	if (amount < 0) {
		throw std::runtime_error("Given a negative amount to Set the liquidity");
	}
	_liquidity = amount;
}

void Bank::addLiquidity(double amount) {
	if (amount < 0) {
		throw std::runtime_error("Given a negative amount to add in the liquidity");
	}
	if (_liquidity > MAX_DOUBLE - amount) {
		throw std::runtime_error("Amount given will overflow liquidity(double)");
	}
	_liquidity += amount;
}

void Bank::addAccount() {
	if (_accountsIds == MAX_UNSIGNED_INT) {
		throw std::runtime_error("Max number of accounts possible achieved");
	}
	Bank::Account* newAccount = new Bank::Account();

	_clientAccounts.insert(std::pair<int, Bank::Account*>(_accountsIds, newAccount));
	_accountsIds++;
}

void Bank::deleteAccount(int accountId) {
	std::map<int, Bank::Account*>::iterator account = _clientAccounts.find(accountId);
	if (account == _clientAccounts.end()) {
		throw std::runtime_error("There's no account with that id");
	}
	delete account->second;
	_clientAccounts.erase(account);
}

void Bank::addMoneyToAccount(Bank::Account* account, double amount) {
	if (account->_money > MAX_DOUBLE - amount) {
		throw std::runtime_error("Adding this much money will overflow account");
	}
	account->_money += amount; 
}

void Bank::depositMoney(int accountId, double depositAmount) {
	std::map<int, Bank::Account*>::iterator account_iter = _clientAccounts.find(accountId);
	if (account_iter == _clientAccounts.end()) {
		throw std::runtime_error("There's no account with that id");
	}
	Bank::Account* account = account_iter->second;
	double amountToBank = depositAmount * 0.05;
	double amountToAccount = depositAmount * 0.95;
	addLiquidity(amountToBank);
	if (account->_loan > 0 && amountToAccount < account->_loan) {
		addLiquidity(amountToAccount);
		account->_loan -= amountToAccount;
	}
	else if (account->_loan > 0 && amountToAccount >= account->_loan) {
		double remainingAmount = amountToAccount - account->_loan;
		addLiquidity(account->_loan);
		account->_loan = 0;
		addMoneyToAccount(account, remainingAmount);
	}
	else {
		addMoneyToAccount(account, amountToAccount);
	}
}

void Bank::withdrawMoney(int accountId, double withdrawAmount) {
	std::map<int, Bank::Account*>::iterator account_iter = _clientAccounts.find(accountId);
	if (account_iter == _clientAccounts.end()) {
		throw std::runtime_error("There's no account with that id");
	}
	Bank::Account* account = account_iter->second;
	if (withdrawAmount > account->_money) {
		throw std::runtime_error("There's not enough money in the account");
	}
	account->_money -= withdrawAmount;
}

void Bank::askForLoan(int accountId, double loanAmount) {
	std::map<int, Bank::Account*>::iterator account_iter = _clientAccounts.find(accountId);
	if (account_iter == _clientAccounts.end()) {
		throw std::runtime_error("There's no account with that id");
	}
	Bank::Account* account = account_iter->second;
	if (loanAmount > _liquidity) {
		throw std::runtime_error("The bank doesn't have enough liquidity");
	}
	if (loanAmount <= 0) {
		throw std::runtime_error("The loan amount is 0 or negative(WTFF)");
	}
	addMoneyToAccount(account, loanAmount);
	account->_loan += loanAmount;
	_liquidity -= loanAmount;
}

Bank::Account::Account(): _money(0), _loan(0) {}

Bank::Account::~Account() {}

double Bank::Account::getMoney() const {
	return _money;
}

double Bank::Account::getLoan() const {
	return _loan;
}