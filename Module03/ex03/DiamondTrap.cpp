/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:08:10 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/24 22:44:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

std::ostream&   operator<<(std::ostream& out, DiamondTrap const& c)
{
	out << "DiamondTrap{";
	out << " name : " << c.getName();
	out << ", hp : " << c.getHP();
	out << ", ep : " << c.getEP();
	out << ", dmg : " << c.getDMG();
	out << " } ";
	return (out);
}

DiamondTrap::DiamondTrap(void) {
    std::cout << "DiamondTrap default costructor called." << std::endl;
    _name = this->ClapTrap::_name;
    this->ClapTrap::_name += "_clap_name";
	this->_hp = this->FragTrap::getHP();
	this->_ep = this->ScavTrap::getEP();
	this->_dmg = this->FragTrap::getDMG();
//	_ep = 50;
//	_dmg = 20;
}
DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name) {
	std::cout << "DiamondTrap constructor called with name : " << name << std::endl;
    _name = name;
    this->ClapTrap::_name += "_clap_name";
	_hp = this->FragTrap::getHP();
	_ep = this->ScavTrap::getEP();
	_dmg = this->FragTrap::getDMG();
}

DiamondTrap::DiamondTrap(DiamondTrap const& d){
	std::cout << "DiamondTrap copy constructor called" << std::endl;

	_name = d.getName();
	_hp = d.getHP();
	_ep = d.getEP();
	_dmg = d.getDMG();
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& d){
	if (this == &d)
		return (*this);
	_name = d.getName();
	_hp = d.getHP();
	_ep = d.getEP();
	_dmg = d.getDMG();
	std::cout << "Copy assignment DONE!" << std::endl;
	return (*this);
}

std::string const&	DiamondTrap::getName(void) const {return (_name);}
unsigned int		DiamondTrap::getHP(void) const {return (_hp);}
unsigned int		DiamondTrap::getEP(void) const {return (_ep);}
unsigned int		DiamondTrap::getDMG(void) const {return (_dmg);}

/*
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& c){
	if (this == &c)
		return (*this);
	_name = c.getName();
	_hp = c.getHP();
	_ep = c.getEP();
	_dmg = c.getDMG();
	std::cout << "Copy assignment DONE!" << std::endl;
	return (*this);
}
*/
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called " << std::endl;
}

void	DiamondTrap::attack(std::string const& target)
{
	this->ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) const
{
    std::cout << "DiamondTrap wonders about his identity : " << _name << " / " << ClapTrap::_name << std::endl;
}
