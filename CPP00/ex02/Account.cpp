#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	// std::cout << "Member function getNbAccounts() called!" << std::endl;
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	// std::cout << "Member function getTotalAmount() called!" << std::endl;
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	// std::cout << "Member function getNbDeposit() called!" << std::endl;
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	// std::cout << "Member function getNbWithdrawals() called!" << std::endl;
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	// std::cout << "static function displayAccountsInfos() called!" << std::endl;

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";";
	std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = getNbAccounts();
	// std::cout << "default constructor Account called!" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:"<< this->_amount << ";";
	std::cout << "created" << std::endl;

	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	// std::cout << "destructor ~Account called!" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:"<< this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	// std::cout << "Member function makeDeposit() called!" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:"<< this->_amount << ";";

	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount  << ";";
	std::cout << "nb_deposits:" << ++(this->_nbDeposits) << ":";
	std::cout << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	// std::cout << "Member function makeWithdrawal() called!" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (this->checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << ++(this->_nbWithdrawals) << std::endl;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const
{
	// std::cout << "Member function checkAmount() called!" << std::endl;
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	// std::cout << "Member function displayStatus() called!" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:"<< this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ":";
	std::cout << std::endl;
}

void Account::_displayTimestamp(void)
{
	// std::cout << "Member function displayTimestamp() called!" << std::endl;
	std::time_t currentTime = std::time(0);
	std::tm* localTime = std::localtime(&currentTime);
    char buffer[80];
    std::strftime(buffer, 80, "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << buffer << "] ";
}