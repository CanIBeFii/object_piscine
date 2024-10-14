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
	if (account->_value > MAX_DOUBLE - amount) {
		throw std::runtime_error("Adding this much money will overflow account");
	}
	account->_value += amount; 
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
	
}