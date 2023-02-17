/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:03:59 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 01:16:01 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string const& name) : _name(name) {}

HumanB::~HumanB(void) {}

void    HumanB::setWeapon(Weapon *weapon) : _weapon(weapon) {}

void    HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their "
        << this->_weapon.getType() << std::endl;
}