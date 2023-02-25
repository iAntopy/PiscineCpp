/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:44:53 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/24 22:44:23 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__
# include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
//	protected:
	
		std::string   _name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_dmg;
		
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const& name);
		DiamondTrap(DiamondTrap const& d);
		~DiamondTrap(void);
		DiamondTrap&	operator=(DiamondTrap const& src);

		std::string const&	getName(void) const;
		unsigned int		getHP(void) const;
		unsigned int		getEP(void) const;
		unsigned int		getDMG(void) const;
		
		void 		   attack(std::string const& target);
		void			whoAmI(void) const;
};

std::ostream&   operator<<(std::ostream& out, DiamondTrap const& c);

#endif