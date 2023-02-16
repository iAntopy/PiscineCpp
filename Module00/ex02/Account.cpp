/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:43:47 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/15 23:51:06 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	gen_timestamp(std::string& ret)
{
	std::stringstream	timestamp;
	std::time_t			t = std::time(nullptr);
	//std::tm*			tm = std::localtime(t);
	timestamp << std::put_time(std::localtime(&t), "%Y%m%d_%H%M%S");
	ret = timestamp.str();
}

int	log_account_creation(int index, int amount)
{
	std::string		timestamp;
	std::ofstream	file;
	std::string		filename;

	timestamp.clear();
	gen_timestamp(timestamp);
	std::cout << "Account created at : " << timestamp << std::endl;
	filename = timestamp;
	filename += ".log";
	file.open(filename, std::ios_base::app);
	file << '[' << timestamp << "] ";
	file << "index:" << index;
	file << "amount:" << amount;
	file << "created";	
//	filename.clear();
	//file.open();
	file.close();
	return (0);
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	std::string		timestamp;
	std::ofstream	file;
	std::string		filename;

	log_account_creation(this->_accountIndex, this->_amount);
	timestamp.clear();
	gen_timestamp(timestamp);
	std::cout << "Account created at : " << timestamp << std::endl;
	filename = timestamp;
	filename += ".log";
	
	file.open(filename, std::ios_base::app);
	file << '[' << timestamp << "] ";
	file << "index:" << this->_accountIndex;
	file << "amount:" << this->_amount;
	file << "created";
	file.close();
	
	this->_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts++;
//	[19920104_091532] index:0;amount:42;created
}

Account::Account(void) : _amount(0)
{
	this->_accountIndex = this->_nbAccounts++;    
}

Account::~Account(void)	{
	std::cout << "Account " << this->_accountIndex << " destroyed" << std::endl;
	this->_nbAccounts--;
}

// Static member variables getters
int  Account::getNbAccounts(void) {
	return (_nbAccounts);}

int  Account::getTotalAmount(void) {
	return (_totalAmount);}

int  Account::getNbDeposits(void) {
	return (_totalNbDeposits);}

int  Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);}


// Local member variables getters
int Account::checkAmount(void) const {
	return (this->_amount);}

// Static methods
void    displayAccountsInfos(void)
{
}

// Local methods
void    Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_nbDeposits++;    
}
bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		std::cerr << "[> ACCOUNT OVERDRAFT ALERT <] : ";
		std::cerr << "Not enough funds to cover withdrawal." << std::endl;
		return (false);
	}
	else if (withdrawal < 0)
	{
		std::cerr << "[> INVALID OPERATION ALLERT <] : ";
		std::cerr << "Withdrawal of absurd amount detected : " << withdrawal << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		return (true);
	}
}

void	Account::displayStatus(void) const
{
}

int	main(void)
{
	Account	acc(42);
	return (0);
}