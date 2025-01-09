#include "Account.hpp"
#include <iostream>

//timestamp
#include <iomanip>      // std::put_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/** getters  */
int	Account::getNbAccounts( void ){
	return _nbAccounts;
}
int	Account::getTotalAmount( void ){
	return _totalAmount;
}
int	Account::getNbDeposits( void ){
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

/** constructor */
Account::Account( int initial_deposit ) : 
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
};
/** destructor */
Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

/** ---------------------- */
void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	++_nbDeposits;
	++_totalNbDeposits;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return false;
	}
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}
int		Account::checkAmount( void ) const {
	return _amount;
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawls:" << _nbWithdrawals << std::endl;
}




void	Account::_displayTimestamp( void )
{
	// Get the current time
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
	std::cout << "[" << std::put_time(localTime,"%Y%m%d_%H%M%S") << "] ";

}