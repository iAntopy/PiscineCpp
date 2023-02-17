/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:55:25 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 01:14:01 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __HUMAN_B_HPP__
# define __HUMAN_B_HPP__

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string const&  _name;
        Weapon*              _weapon;
        
    public:
        HumanB(std::string const& name);
        ~HumanB();
        
        void    setWeapon(Weapon* weapon);
        void    attack(void);
};

#endif
