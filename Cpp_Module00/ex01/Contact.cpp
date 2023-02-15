/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:46:50 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/13 00:18:58 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstring>

Contact::Contact(void)
{
	this->_isInit = 0;
	return ;
}

Contact::~Contact(void)
{
}

std::string const&	Contact::getFirstName(void) const
{
	return (this->_fname);
}

std::string const&	Contact::getLastName(void) const
{
	return (this->_lname);
}

std::string const&	Contact::getNickName(void) const
{
	return (this->_nname);
}

std::string const&	Contact::getPhoneNum(void) const
{
	return (this->_phone);
}

std::string const&	Contact::getDarkSecret(void) const
{
	return (this->_darkness);
}

int	Contact::getIsInit(void)
{
	return (this->_isInit);
}

int	Contact::setIsInit(void)
{
	if (this->_fname.length() != 0
		&& this->_lname.length() != 0
		&& this->_nname.length() != 0
		&& this->_phone.length() != 0
		&& this->_darkness.length() != 0)
	{
		this->_isInit = 1;
		return (0);
	}
	std::cout << "Contact is missing data and is not initialized properly" << std::endl;
	this->_isInit = 0;
	return (-1);
}

int	Contact::setFirstName(std::string const& name)
{
	if (name.length() == 0)// || name[0] == std::endl)
	{
		std::cerr << "Please enter your contact's first name." << std::endl;
		return (-1);
	}
	this->_fname = name;
	return (0);
}

int	Contact::setLastName(std::string const& name)
{
	if (name.length() == 0)// || name[0] == std::endl)
	{
		std::cerr << "Please enter your contact's last name." << std::endl;
		return (-1);
	}
	this->_lname = name;
	return (0);
}

int	Contact::setNickName(std::string const& name)
{
	if (name.length() == 0)// || name[0] == std::endl)
	{
		std::cerr << "Please enter your contact's nickname." << std::endl;
		return (-1);
	}
	this->_nname = name;
	return (0);
}

int	Contact::setPhoneNum(std::string const& num)
{
	if (num.length() == 0)// || num[0] == std::endl)
	{
		std::cerr << "Please enter your contact's phone number." << std::endl;
		return (-1);
	}
	this->_phone = num;
	return (0);
}

int	Contact::setDarkSecret(std::string const& secret)
{
	if (secret.length() == 0)// || secret[0] == std::endl)
	{
		std::cerr << "Please enter your contact's darkest secret." << std::endl;
		return (-1);
	}
	this->_darkness = secret;
	return (0);
}
