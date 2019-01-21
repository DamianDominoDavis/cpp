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

/*
**	static var, fnct
*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_nbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_nbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	std::cout << "index:" << 6
		<< ";p_amount:" << 754
		<< ";deposit:" << 9
		<< ";amount:" << 763
		<< ";nb_deposits:" << 1
		<< "\n";
}

Account(int initial_deposit) {
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts++;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	
	return (this);
}

~Account(void) {
	this->_amount = 0;
	Account::_nbAccounts++;
	return (this);
}

void	Account::makeDeposit(int deposit) {
	this->_amount += deposit;
	Account::_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		Account::_nbWithdrawals++;
		return (true);
	}
	return (false);
}

int		Account::checkAmount(void) {
	return (this->_amount);
}

void	Account::displayStatus(void) const;


private static void	_displayTimestamp(void);
