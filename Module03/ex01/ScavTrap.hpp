/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:50:30 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/22 07:00:20 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string const& name);
		ScavTrap(ScavTrap const& src);
		~ScavTrap();

		ScavTrap&	operator=(ScavTrap const& src);

		void    attack(std::string const& target) override;
		void	guardGate(void) const;
};

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i );

#endif
