/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:22:46 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/24 22:43:49 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ClapTrap.hpp"

std::ostream&   operator<<(std::ostream& out, ClapTrap const& c)
{
	out << "ClapTrap{";
	out << "name : " << c.getName();
	out << "hp : " << c.getHP();
	out << "ep : " << c.getEP();
	out << "dmg : " << c.getDMG();
	out << "} " << std::endl;
	return (out);
}

ClapTrap::ClapTrap(void) : _name("DEFAULT"), _hp(10), _ep(10), _dmg(0) {
	std::cout << "ClapTrap default costructor called." << std::endl;
}
ClapTrap::ClapTrap(std::string const& name) : _name(name), _hp(10), _ep(10), _dmg(0) {
	std::cout << "ClapTrap constructor called with name : " << name << std::endl;
}
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called " << std::endl;
}
ClapTrap&	ClapTrap::operator=(ClapTrap const& c){
	if (this == &c)
		return (*this);
	_name = c.getName();
	_hp = c.getHP();
	_ep = c.getEP();
	_dmg = c.getDMG();
	std::cout << "Copy assignment DONE!" << std::endl;
	return (*this);
}

std::string const&	ClapTrap::getName(void) const {return (_name);}
unsigned int		ClapTrap::getHP(void) const {return (_hp);}
unsigned int		ClapTrap::getEP(void) const {return (_ep);}
unsigned int		ClapTrap::getDMG(void) const {return (_dmg);}
void				ClapTrap::setDMG(unsigned int amount) {_dmg = amount;}

bool	ClapTrap::isDead(void) const {return (_hp == 0);}

void    ClapTrap::attack(std::string const& target)
{
	if (this->isDead())
	{
		std::cout << _name << " has a hard time clapping his enemies while dead..." << std::endl;
		return ;
	}
	else if (_ep == 0)
	{
		std::cout << _name << " is too tired to fight. They cough their lungs out while bent over and ask their opponents for a timeout. What a shame." << std::endl;
		return ;
	}
	_ep--;
	std::cout << "Claptrap " << _name << " attacks " << target
		<< " causing " << _dmg << " points of dammage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if (this->isDead())
	{
		std::cout << "No point in beating a dead horse. " << _name << " is already dead." << std::endl;
		return ;
	}
	if (amount >= _hp)
	{
		_hp = 0;
		std::cout << _name << " dies and brings shame to his family." << std::endl;
	}
	else
	{
		_hp -= amount;
		std::cout << _name << " receives " << amount << " points of damage and laughs at his opponent's weakness." << std::endl;
	}
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isDead())
	{
		std::cout << "Moggots have already consumed " << _name << "'s body. I'm afraid repairs are not an option." << std::endl;
		return ;
	}
	else if (_ep == 0)
	{
		std::cout << _name << " is too tired to help himself. MEDIC !" << std::endl;
		return ;
	}
	_hp += amount;
	std::cout << _name << " repairs itself and gains "<< amount
	<< " HP. Current HP : " << _hp << std::endl;
}