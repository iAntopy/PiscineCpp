/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:43:47 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/16 22:30:02 by iamongeo         ###   ########.fr       */
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

static bool	open_log_file(std::ofstream& file, std::string& timestamp)
{
	std::string		filename;
	
//	filename = "logs/";
	filename += timestamp;
	filename += ".log";
	file.open(filename, std::ios_base::app);
	if (!file)
	{
		std::cerr << "Log file open failed" << std::endl;
		return (false);
	}
	file << '[' << timestamp << "] ";
	return (true);
}

static int	log_account_creation(int index, int amount)
{
	std::string		timestamp;
	std::ofstream	file;

	gen_timestamp(timestamp);
	if (open_log_file(file, timestamp))
	{
		std::cout << "Account created at : " << timestamp << std::endl;
		file << "index:" << index;
		file << ";amount:" << amount;
		file << ";created" << std::endl;	
		file.close();
	}
	return (0);
}

static int	log_account_destruction(int index, int amount)
{
	std::string		timestamp;
	std::ofstream	file;

	gen_timestamp(timestamp);
	if (open_log_file(file, timestamp))
	{
		std::cout << "Account closed at : " << timestamp << std::endl;
		file << "index:" << index;
		file << ";amount:" << amount;
		file << ";closed" << std::endl;	
		file.close();
	}
	return (0);
}

static int	log_AccountsInfos(int nbAccounts, int amount, int nbDeps, int nbWit)
{
	std::string		timestamp;
	std::ofstream	file;

	gen_timestamp(timestamp);
	if (open_log_file(file, timestamp))
	{
		file << "accounts:" << nbAccounts;
		file << ";total:" << amount;
		file << ";deposits:" << nbDeps;	
		file << ";withdrawals:" << nbWit << std::endl;
		file.close();
	}
	return (0);
}

static int	log_deposit(int index, int amount, int depAmount, int nbDeps)
{
	std::string		timestamp;
	std::ofstream	file;

	gen_timestamp(timestamp);
	if (open_log_file(file, timestamp))
	{
		file << "index:" << index;
		file << ";p_amount:" << amount - depAmount;
		file << ";deposit:" << depAmount;
		file << ";amount:" << amount;
		file << ";nb_deposits:" << nbDeps << std::endl;
		file.close();
	}
	return (0);
}

static int	log_withdrawal(int index, int amount, int witAmount, int nbWits)
{
	std::string		timestamp;
	std::ofstream	file;

	gen_timestamp(timestamp);
	if (open_log_file(file, timestamp))
	{
		file << "index:" << index;
		if (witAmount == -1)
		{
			file << ";p_amount:" << amount;
			file << ";withdrawal:refused" << std::endl;
		}
		else
		{
			file << ";p_amount:" << amount + witAmount;
			file << ";withdrawal:" << witAmount;
			file << ";amount:" << amount;
			file << ";nb_withdrawals:" << nbWits << std::endl;
		}
		file.close();
	}
	return (0);
}

void	Account::displayStatus(void) const
{
	std::string		timestamp;
	std::ofstream	file;

	gen_timestamp(timestamp);
	if (open_log_file(file, timestamp))
	{
		file << "index:" << this->_accountIndex;
		file << ";amount:" << this->_amount;
		file << ";deposits:" << this->_nbDeposits;
		file << ";withdrawals:" << this->_nbWithdrawals << std::endl;
		file.close();
	}
}

void	Account::_displayTimestamp(void)
{
	std::string		timestamp;
	gen_timestamp(timestamp);
	std::cout << timestamp << std::endl;	
}

Account::Account(int initial_deposit) : _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	std::string		timestamp;
	std::ofstream	file;
	std::string		filename;

	log_account_creation(this->_accountIndex, this->_amount);
	this->_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts++;
}

Account::Account(void) : _amount(0)
{
	this->_accountIndex = this->_nbAccounts++;    
}

Account::~Account(void)	{
//	std::cout << "Account " << this->_accountIndex << " destroyed" << std::endl;

	log_account_destruction(this->_accountIndex, this->_amount);
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
void    Account::displayAccountsInfos(void)
{
	log_AccountsInfos(Account::getNbAccounts(), Account::getTotalAmount(),
		Account::getNbDeposits(), Account::getNbWithdrawals());
}

// Local methods
void    Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	log_deposit(this->_accountIndex, this->_amount, deposit, this->_nbDeposits);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		std::cerr << "[> ACCOUNT OVERDRAFT ALERT <] : ";
		std::cerr << "Not enough funds to cover withdrawal." << std::endl;
		log_withdrawal(this->_accountIndex, this->_amount, -1, this->_nbWithdrawals);
		return (false);
	}
	else if (withdrawal < 0)
	{
		std::cerr << "[> INVALID OPERATION ALLERT <] : ";
		std::cerr << "Withdrawal of absurd amount detected : " << withdrawal << std::endl;
		log_withdrawal(this->_accountIndex, this->_amount, -1, this->_nbWithdrawals);
		return (false);
	}
	else
	{
		//int index, int p_amount, int witAmount, int nbWits)
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		log_withdrawal(this->_accountIndex, this->_amount, withdrawal, this->_nbWithdrawals);
		return (true);
	}
}
/*
int	main(void)
{
	Account	acc(42);
	acc.displayAccountsInfos();
	acc.displayStatus();

	acc.makeDeposit(999);
	acc.makeWithdrawal(42);
	
	acc.displayAccountsInfos();
	acc.displayStatus();
	return (0);
}
*/