/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:46:03 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 00:18:34 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie(void){
    std::cout << this->_name << " dies a meaningless death." << std::endl;
}

void    Zombie::setName(std::string& name)
{
    this->_name = name;
}

void    Zombie::annonce(void)
{
    std::cout << "hello" << std::endl;
    //std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}