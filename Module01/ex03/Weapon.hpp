/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:49:24 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 01:18:16 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <string>

class Weapon
{
    private:
        std::string _type;
        
    public:
        Weapon(std::string const& type);
        ~Weapon(void);

        std::string const&  getType(void);
        void                setType(std::string const& type);
};

#endif