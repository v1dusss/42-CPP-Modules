#include "Account.hpp"
#include <ctime>
#include <iostream>

	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;
	int Account::_nbAccounts = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}


void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";p_amount:"<< _amount;

	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	this->_amount += deposit;

	std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";p_amount:"<< _amount;

	if (withdrawal <= this->_amount) {
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	else {
		std::cout << ";withdrawal:" << "refused" << std::endl;
	}
	return (_nbWithdrawals != 0);
}


void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t timer;
	struct tm *timeInfo;
	char buffer[20];

	time(&timer);
	timeInfo = localtime(&timer);

	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeInfo);

	std::cout << buffer << " ";
}

int Account::checkAmount(void) const
{
	return this->_amount;
}
