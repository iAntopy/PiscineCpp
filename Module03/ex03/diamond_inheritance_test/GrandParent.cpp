/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrandParent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:33:14 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/22 22:53:40 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GrandParent.hpp"
#include <iostream>

GrandParent::GrandParent(void) : _hp(10) {
//    std::cout << "sizeof GrandParent : " << sizeof(GrandParent) << std::endl;
}
GrandParent::~GrandParent(void) {}

int GrandParent::getHP(void) const {return this->_hp;}


Parent1::Parent1(void) : GrandParent() {
    this->_hp = 30;
    std::cout << "Parent1 hp : " << this->getHP() << ", _hp : " << this->_hp << std::endl;
    
    std::cout << "sizeof Parent1 : " << sizeof(Parent1) << std::endl;
}//this->GrandParent::getHP();}
Parent1::~Parent1(void) {}

//int Parent1::getHP(void) const {return (this->_hp);}

Parent2::Parent2(void) : GrandParent()
{
    std::cout << "Parent2 constructor : " << std::endl;
 //   std::cout << "_hp before Parent2 setup : " << _hp << std::endl;
    this->_hp = 20;
 //   std::cout << "_hp after Parent2 setup : " << _hp << std::endl;
//    std::cout << "Parent2 hp : " << this->getHP() << ", _hp : " << this->_hp << std::endl;
    std::cout << "sizeof Parent2 : " << sizeof(Parent2) << std::endl;
}
Parent2::~Parent2(void) {}

//int Parent2::getHP(void) const {return (this->_hp);}

Child::Child(void) : Parent1(), Parent2(), _hp(this->Parent1::_hp)//getHP())
{
    this->_hp = this->Parent1::_hp;//getHP();
 //   std::cout << "Parent1::getHP() : " << this->Parent1::getHP() << std::endl;
  //  std::cout << "_hp : " << this->_hp << std::endl;
    //std::cout << "Child hp : " << this->getHP() << ", _hp : " << this->_hp << std::endl;
    std::cout << "sizeof Child : " << sizeof(Child) << std::endl;
}
Child::~Child(void) {}

int Child::getHP(void) const {return (this->_hp);}
