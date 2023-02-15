/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:25:48 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/13 01:31:45 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iostream>
#include <ios>
#include <iomanip>

void	pb_msg(std::string const& msg, int nb_nl)
{
	std::cout << PB_OUT_PROMPT << msg;
	while (nb_nl--)
		std::cout << std::endl;
}

void	pb_input_prompt(std::string& ret)
{
	std::cout << PB_IN_PROMPT;
	std::getline(std::cin, ret);
}


PhoneBook::PhoneBook(void)
{
	this->_total_entries = 0;
}

PhoneBook::~PhoneBook(void)
{
}

int	PhoneBook::_getNbEntries(void)
{
	return (this->_total_entries);
}

Contact&	PhoneBook::_getNextContact(void)
{
	return (this->_contacts[this->_getNbEntries() % MAX_ENTRIES]);
}

Contact const&	PhoneBook::getLastEntry(void)
{
	return (this->_contacts[(this->_getNbEntries() - 1) % MAX_ENTRIES]);
}

int	reset_cin()
{
	std::cin.clear();
	std::clearerr(stdin);
	return (-1);
}

int	prompt_single_data_entry(Contact& c, std::string const& prompt, std::string& entry)
{
	entry.clear();
	std::cout << PB_OUT_PROMPT << prompt;
	while (getline(std::cin, entry) && entry.empty())
		std::cout << PB_OUT_PROMPT << prompt;
	if (entry.empty())
		return (reset_cin());
//	c.setFirstName(entry);
//	entry.clear();
	return (0);
}

int	PhoneBook::add(void)
{
	Contact&	c = this->_getNextContact();
	std::string	entry;

        if (c.getIsInit())
            std::cout << PB_OUT_PROMPT << "OVERWRITING BORING OLD FRIEND : " << c.getFirstName() << " " << c.getLastName() << std::endl;
	entry.clear();
	if (prompt_single_data_entry(c, "First name :\t\t", entry) < 0 || c.setFirstName(entry) < 0
		|| prompt_single_data_entry(c, "Last name :\t\t", entry) < 0 || c.setLastName(entry) < 0
		|| prompt_single_data_entry(c, "Nickname :\t\t", entry) < 0 || c.setNickName(entry) < 0
		|| prompt_single_data_entry(c, "Phone number :\t\t", entry) < 0 || c.setPhoneNum(entry) < 0
		|| prompt_single_data_entry(c, "Darkest Secret :\t", entry) < 0 || c.setDarkSecret(entry) < 0)
		return (-1);
	entry.clear();
	this->_total_entries++;
	c.setIsInit();
	return (0);
/*
	std::cout << "First name : ";
	while (getline(std::cin, entry) && entry.empty())
		std::cout << "First name : ";
	if (entry.empty())
		return (reset_cin());
	c.setFirstName(entry);
	entry.clear();
	
	std::cout << "Last name : ";
	while (getline(std::cin, entry) && entry.empty())
		std::cout << "Last name : ";
	if (entry.empty())
		return (reset_cin());
	c.setLastName(entry);
	entry.clear();

	std::cout << "Nickname : ";
	while (getline(std::cin, entry) && entry.empty())
		std::cout << "Nickname : ";
	if (entry.empty())
		return (reset_cin());
	c.setNickN
        ame(entry);
	entry.clear();
	
	std::cout << "Phone number : ";
	while (getline(std::cin, entry) && entry.empty())
		std::cout << "Phone number : ";
	if (entry.empty())
		return (reset_cin());
	c.setPhoneNum(entry);
	entry.clear();
	
	std::cout << "Darkest secret : ";
	while (getline(std::cin, entry) && entry.empty())
		std::cout << "Darkest secret : ";
	if (entry.empty())
		return (reset_cin());
	c.setDarkSecret(entry);
*/
}

void	print_single_table_entry(std::string const& ent)
{
//	std::cout << "|";
	if (ent.length() > 10)
	{
		std::cout.write(ent.c_str(), 9);
		std::cout << ".|";
	}
	else
		std::cout << std::setw(10) << ent << '|';
}

int	prompt_search_index(void)
{
	int	index;

	std::cout << PB_OUT_PROMPT << "Which on of those lovely people you wanna know more about : " << std::endl;
	index = 0;
	while (!(1 <= index && index <= 8))
	{
		std::cout << PB_IN_PROMPT << "index :\t";
		if (!(std::cin >> index))
                {
                pb_msg("", 1);
                    pb_msg("Hmmm ... maybe numbers aren't your thing. We can come back here later when you're ready.", 2);
                    return (-1);
                }
		std::cout << std::endl;
		if (index <= 0 || 8 < index)
			std::cerr << PB_OUT_PROMPT << "Silly you ... my chip only has space for 8 friends indexed [1-8]." \
				<< " Try an index in that range" << std::endl;
	}
	return (index);
}

int	PhoneBook::search(void)
{
//	std::string	index;
	int	index;

        if (this->_total_entries == 0)
        {
            int pick = std::rand() % 3;

            std::cerr << PB_OUT_PROMPT << "Seems you don't know anybody yet. " << std::endl;
            if (pick == 0)
                std::cerr << PB_OUT_PROMPT << "I'd introduce you to my 8-bit friends, but they're usually pretty stiff." << std::endl;
            else if (pick == 1)
                std::cerr << PB_OUT_PROMPT << "I'd introduce you to my 8-bit friends, but they're all kinda BASIC." << std::endl;
            else
                std::cerr << PB_OUT_PROMPT << "I'd introduce you to my 8-bit friends, but {INSERT hilarious_jokes[" << std::rand() % 100 << "]}." << std::endl;
            return (0);
        }
	pb_msg("So you want to look up someone ? Here's a curated list of the best people you know.", 2);
	std::cout << PB_OUT_PROMPT << "+----------+-----[ CONTACTS ]----+----------+" << std::endl;
	std::cout << PB_OUT_PROMPT << "|    index |  fstname | lastname | nickname |" << std::endl;
	std::cout << PB_OUT_PROMPT << "+----------+----------+----------+----------+" << std::endl;
	for (int i=0; i < MAX_ENTRIES; i++)
	{
		Contact&	c = this->_contacts[i];
		if (i >= this->_total_entries || !c.getIsInit())
			break ;

		std::cout << PB_OUT_PROMPT << '|' << std::setw(10) << (i + 1) << '|';
		print_single_table_entry(c.getFirstName());
		print_single_table_entry(c.getLastName());
		print_single_table_entry(c.getNickName());
		std::cout << std::endl;
	}
	std::cout << PB_OUT_PROMPT << "+----------+----------+----------+----------+" << std::endl << std::endl;

        Contact *C; 
	while (1)
	{
		index = prompt_search_index();
                if (index == -1)
                    return (reset_cin());
                std::cout << "index received : " << index << std::endl;
		C = &this->_contacts[index - 1];
                std::cout << "C is init ? " << C->getIsInit() << std::endl;
		if (!C->getIsInit())
			std::cerr << PB_OUT_PROMPT << "Silly you ... You have no friend corresponding to index " << index << std::endl;
		else
			break ;
	}
	std::cout << PB_OUT_PROMPT << "Here's everything I know about " << C->getFirstName() << " " << C->getLastName() << std::endl << std::endl;
	std::cout << PB_OUT_PROMPT << "\t- First Name :\t\t" << C->getFirstName() << std::endl;
	std::cout << PB_OUT_PROMPT << "\t- Last Name :\t\t" << C->getLastName() << std::endl;
	std::cout << PB_OUT_PROMPT << "\t- Nickname :\t\t" << C->getNickName() << std::endl;
	std::cout << PB_OUT_PROMPT << "\t- Phone number :\t\t" << C->getPhoneNum() << std::endl;
	std::cout << PB_OUT_PROMPT << "\t- Darkest secret :\t" << C->getDarkSecret() << std::endl << std::endl;
	std::cout << PB_OUT_PROMPT << "They seem great. You should give'em a call." << std::endl << std::endl;
//	std::cout << "SEARCH requested" << std::endl;
        return (0);
}
