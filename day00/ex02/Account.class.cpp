// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include <iostream>
#include "Account.class.hpp"

/*
**	static var, fnct
*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void) {
	std::cout << "[00000000_000000]";
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/*
**	construct
*/

Account::Account(int initial_deposit) {
	_amount = initial_deposit;
	_accountIndex = Account::_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
}

Account::~Account(void) {
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

/*
**	obj fnct
*/

int		Account::checkAmount(void) const {
	return (_amount);
}

void	Account::makeDeposit(int deposit) {
	if (deposit > 0) {
		_amount += deposit;
		_nbDeposits++;
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
		Account::_displayTimestamp();
		std::cout << " index:" << _accountIndex
			<< ";p_amount:" << (_amount - deposit)
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
	}
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > 0 && _amount >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << " index:" << _accountIndex
			<< ";p_amount:" << (_amount + withdrawal)
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
	return (false);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}
