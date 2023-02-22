/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:51:08 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/22 06:58:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap default costructor called." << std::endl;
	_hp = 100;
	_ep = 50;
	_dmg = 20;
}
ScavTrap::ScavTrap(std::string const& name) {
	std::cout << "ScavTrap constructor called with name : " << name << std::endl;
	_name = name;
	_hp = 100;
	_ep = 50;
	_dmg = 20;
}
ScavTrap&	ScavTrap::operator=(ScavTrap const& c){
	if (this == &c)
		return (*this);
	_name = c.getName();
	_hp = c.getHP();
	_ep = c.getEP();
	_dmg = c.getDMG();
	std::cout << "Copy assignment DONE!" << std::endl;
	return (*this);
}
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called " << std::endl;
}

void	ScavTrap::attack(std::string const& target) 
{
	if (this->isDead())
	{
		std::cout << _name << " has transcended the need for physical violence. Although, haunting people has become a hobby." << std::endl;
		return ;
	}
	else if (_ep == 0)
	{
		std::cout << _name << "'s spirit is down, but they shall never give up." << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ScavTrap " << _name << " mauls " << target
		<< " causing " << _dmg << " points of dammage!" << std::endl;
}

void	ScavTrap::guardGate(void) const
{
	if (this->isDead())
	{
		std::cout << "While dead, " << _name << "'s limp, lifeless body lays in front of the gate. A band of rambunctious children come pick at the body with sticks and form lifelong memories." << std::endl;
		return ;
	}
	else if (_ep == 0)
	{
		std::cout << "Exhausted, " << _name << " walks towards the gate and get knock down by a gust of wind. Having noticed the event, the local mailman laughs at the misfortune, then goes alongwith his day. " << _name << " was not present at the gate that day." << std::endl;
		return ;
	}
	std::cout << "Scavtrap " << _name << " enters Gate Keeper mode. ";
	std::cout << "What the gate keeps is a mystery to " << _name << " but they feel strongly that it's worth guarding." << std::endl;
}
