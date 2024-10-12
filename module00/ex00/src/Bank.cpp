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
	for (std::map<int, Account *>::iterator iter = _clientaccounts.begin();
		iter != _clientAccounts.end();
		++iter) {
			delete *iter;
		}
}

std::map<int, Account *>& Bank::getAllAccounts() {
	return _clientAccounts;
}

std::map<int, Account *>& Bank::getAllAccounts() const {
	return _clientAccounts;
}

double Bank::getLiquidity() {
	return _liquidity;
}

double Bank::getLiquidity() const {
	return _liquidity;
}

void Bank::setLiquidity(double amount) throw std::runtime_error{
	if (amount < 0) {
		throw std::runtime_error("Given a negative amount to Set the liquidity");
	}
	_liquidity = amount;
}

void Bank::addLiquidity(double amount) throw runtime_error {
	if (amount < 0) {
		throw std::runtime_error("Given a negative amount to add in the liquidity");
	}
	if (_liquidity > MAX_DOUBLE - amount) {
		throw std::runtime_error("Amount given will overflow liquidity(double)");
	}
	_liquidity += amount;
}

void Bank::addAccount() throw std::runtime_error{
	if (_accountsIds == MAX_UNSIGNED_INT) {
		throw std::runtime_error("Max number of accounts possible achieved");
	}
	Account* newAccount = new Bank::Account();

	_clientAccounts.insert(std::pair<int, Account*>(_accountsIds, newAccount));
	_accountsIds++;
}

void Bank::deleteAccount(int accountId) throw std::runtime_error {
	account = _clientAccounts.find(account);
	if (account == _clientAccounts.end()) {
		throw std::runtime_error("There's no account with that id");
	}
	delete account->second;
	_clientAccounts.erase(account);
}


void Bank::depositMoney(int accountId, double depositAmount) throw std::runtime_error {
	account = _clientAccounts.find(accountId);
	if (account == _clientAccounts.end()) {
		throw std::runtime_error("There's no account with that id");
	}
	amountToBank = depositAmount * 0.05;
	amountToAccount = deposirAmount * 0.95;
	if (_liquidity > MAX_DOUBLE - amountToBank)
}