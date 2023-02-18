/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:04:53 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 22:20:28 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) {
	_complainers[0] = &Harl::debug;
	_complainers[1] = &Harl::info;
	_complainers[2] = &Harl::warning;
	_complainers[3] = &Harl::error;
	_ids[0] = "DEBUG";
	_ids[1] = "INFO";
	_ids[2] = "WARNING";
	_ids[3] = "ERROR";
}

Harl::~Harl(void) {}

void    Harl::debug(void)
{
	std::cout << "I love having extra bacon for my\
7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void    Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void    Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming \
for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
	int         i;
	
	for (i=0; i < 4; i++)
	{
		if (this->_ids[i] == level)
		{
			(this->*_complainers[i])();
			return ;
		}
	}
	const int	ci = i;
	switch (ci)
	{
		case 0:
			this->debug();
			break;
		case 1:
			this->info();
			break;
		case 2:
			this->warning();
			break;
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}