/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:04:53 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/18 23:18:08 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(std::string const& filter) {
	_complainers[0] = &Harl::debug;
	_complainers[1] = &Harl::info;
	_complainers[2] = &Harl::warning;
	_complainers[3] = &Harl::error;
	_ids[0] = "DEBUG";
	_ids[1] = "INFO";
	_ids[2] = "WARNING";
	_ids[3] = "ERROR";
	_filterIndex = 0;
	if (!filter.empty())
	{
		for (; _filterIndex < 4; _filterIndex++)
			if (filter == _ids[_filterIndex])
				break ;		
	}
}

Harl::~Harl(void) {}

void    Harl::debug(void)
{
	std::cout << "I love having extra bacon for my\
7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl << std::endl;
}

void    Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}

void    Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming \
for years whereas you started working here since last month." << std::endl << std::endl;
}

void    Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}

void    Harl::complain(std::string level)
{
	switch (_filterIndex)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
//			break;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
//			break;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
//			break;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
//			break;
	}
}