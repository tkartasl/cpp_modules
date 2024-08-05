/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:07:33 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/05 11:16:03 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	return;
}

Account::~Account( void )
{
	return;	
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
 return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

 void	Account::displayAccountsInfos( void )
{

}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->_amount)
		return false;
	this->_amount -=withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	return true;
}

int	Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	
}

static void	_displayTimestamp( void )
{
	std::time_t now = time(0);
	struct tm *local_time = localtime(&now);
	char* date_time = asctime(local_time);
	std::cout << "[" << date_time << "] ";
}