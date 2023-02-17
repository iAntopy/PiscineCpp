/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:03:59 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 01:09:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string const& name, Weapon& weapon)
    : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their "
        << this->_weapon.getType() << std::endl;
}