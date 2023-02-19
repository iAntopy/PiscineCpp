/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:26:59 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/18 22:49:33 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

class Harl
{
	typedef void (Harl::*memFunc_p)(void);
	
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		std::string	_ids[4];
		memFunc_p	_complainers[4];
		int			_filterIndex;
		
	public:
		Harl(std::string const& filter);
		~Harl();

		void	complain(std::string level);
};

#endif