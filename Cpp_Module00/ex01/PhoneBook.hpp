/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:22:32 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/13 00:46:54 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# define YELLOW_BC	"\033[1;33m"
# define WHITE_C	"\033[0;37m"
# define PURPLE_BC	"\033[1;35m"
# define CYAN_BC	"\033[1;36m"
# define MAX_ENTRIES 8
# define PB_OUT_PROMPT CYAN_BC "~" YELLOW_BC "@" WHITE_C "\t"
# define PB_IN_PROMPT YELLOW_BC "--" CYAN_BC ">" WHITE_C "\t"
# include "Contact.hpp"

void	pb_msg(std::string const& msg, int nb_nl);
void	pb_input_prompt(std::string& ret);

class	PhoneBook {

	private:
		int		_total_entries;
		Contact		_contacts[MAX_ENTRIES];
		
		int		_getNbEntries(void);
		Contact&	_getNextContact(void);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		add(void);
		int		search(void);
		Contact const&	getLastEntry(void);
};

#endif
