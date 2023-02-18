/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:49:36 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 17:07:53 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string const& str)
{
    this->setType(str);
}

Weapon::~Weapon(void) {}

void
Weapon::setType(std::string const& type){
    this->_type = type;}

std::string const&
Weapon::getType(void){
    return (this->_type);}

