/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:50:30 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/22 06:56:58 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FragTrap_HPP__
# define __FragTrap_HPP__

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(std::string const& name);
		FragTrap(FragTrap const& src);
		~FragTrap();

		FragTrap&	operator=(FragTrap const& src);

		void	highFivesGuys(void);
};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif
