/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:37:31 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/15 18:41:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__CONTACT_H__
# define __CONTACT_H__

#include <string>

class	Contact {

	private:
		int			_isInit;
		std::string	_fname;
		std::string	_lname;
		std::string	_nname;
		std::string	_phone;
		std::string	_darkness;

	public:
		Contact(void);
		~Contact(void);
		
		std::string const&	getFirstName(void) const;
		std::string const&	getLastName(void) const;
		std::string const&	getNickName(void) const;
		std::string const&	getPhoneNum(void) const;
		std::string const&	getDarkSecret(void) const;

		int			setFirstName(std::string const& name);
		int			setLastName(std::string const& name);
		int			setNickName(std::string const& name);
		int			setPhoneNum(std::string const& nbr);
		int			setDarkSecret(std::string const& secret);
		int			setIsInit(void);
		int			getIsInit(void);

};

#endif
