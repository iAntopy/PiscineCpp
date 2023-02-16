/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:10:17 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/15 17:56:18 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
//#include <cstdlib>
#include <ctime>

void	display_title(void)
{
	std::cout << CYAN_BC << "@@@" << PURPLE_BC << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << CYAN_BC << "@@@" << std::endl;
	std::cout << YELLOW_BC;
	std::cout << " (    ____    _   _     U  ___ u  _   _   U _____ u   ____     U  ___ u   U  ___ u   _  __   ) " << std::endl;
 	std::cout << " )  U|  _\"\\ u|'| |'|     \\/\"_ \\/ | \\ |\"|  \\| ___\"|/U | __\")u    \\/\"_ \\/    \\/\"_ \\/  |\"|/ /   ( " << std::endl;
 	std::cout << " (  \\| |_) |/| |_| |\\    | | | |<|  \\| |>  |  _|\"   \\|  _ \\/    | | | |    | | | |  | ' /    ) " << std::endl;
 	std::cout << " )   |  __/ U|  _  |u.-,_| |_| |U| |\\  |u  | |___    | |_) |.-,_| |_| |.-,_| |_| |U/| . \\u   ( " << std::endl;
 	std::cout << " (   |_|     |_| |_|  \\_)-\\___/  |_| \\_|   |_____|   |____/  \\_)-\\___/  \\_)-\\___/   |_|\\_\\   ) " << std::endl;
 	std::cout << " )   ||>>_   //   \\\\       \\\\    ||   \\\\,-.<<   >>  _|| \\\\_       \\\\         \\\\   ,-,>> \\\\,-.( " << std::endl;
 	std::cout << " (  (__)__) (_\") (\"_)     (__)   (_\")  (_/(__) (__)(__) (__)     (__)       (__)   \\.)   (_/ ) " << std::endl;
	std::cout << CYAN_BC << "@@@" << PURPLE_BC << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << CYAN_BC << "@@@" << std::endl << std::endl;
	std::cout << WHITE_C;
}
/*
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
*/

void	display_intro_msg(void)
{
	std::srand(std::time(nullptr));
	int	pick = std::rand() % 3;

	display_title();
	pb_msg("WELCOME to your very own, top of the line, Friendly Phone Book (tm). Or PB for short.", 1);
	pb_msg("I am designed to help you in exactly 3 ways.", 1);
	pb_msg("Enter one of these commands to help me help you today :", 2);
	pb_msg("	- ADD		: To add a cute new date to the list (wink!)", 1);
	pb_msg("	- SEARCH	: To help you remember those you forgot about.", 1);
	pb_msg("	- EXIT		: To help you forget those you wish you didn't know.", 2);
	pb_msg("What will it be my friend ?", 1);
	
	if (pick == 0)
		pb_msg("You and I will make this day so much better I can tell.", 2);
	else if (pick == 1)
		pb_msg("I got a feeling there's something on your mind. I think I can help.", 2);
	else
		pb_msg("Let's not waist time. I can sense you'll be busy today.", 2);
}

int	prompt_user(PhoneBook& pb)
{
	std::srand(std::time(nullptr));
	int		pick = std::rand() % 3;
	std::string	entry;

	if (pick == 0)
		pb_msg("So what's up ? ", 1);
	else if (pick == 1)
		pb_msg("What's on your mind ? ", 1);
	else
		pb_msg("Drop it on me baby ! ", 1);
	
	if (pb_input_prompt(entry) < 0)
		return (0);
	if (entry.substr(0,3) == "ADD")
	{
//		pb_msg("ADD", 1);
		pb_msg("So who's the lucky one. Come on tell me. I can keep secrets.", 1);
		if (pb.add() < 0)
		{
			std::cout << std::endl;
			pb_msg("Seems there was a problem creating this new contact. Must not have been the right one I suppose.", 1);
		}
		else
		{
			Contact const&	c = pb.getLastEntry();
			std::cout << PB_OUT_PROMPT << c.getFirstName() << " hey. Can't wait to hear more about them." << std::endl;
		}
	}
	else if (entry.substr(0,6) == "SEARCH")
		pb.search();
	else if (entry.substr(0,4) == "EXIT")
		return (-1);
	else if (entry.empty())
	{
		pb_msg("WHAT !? I CAN'T HEAR YOU !", 1);
	}
	else 
	{
		std::srand(std::time(nullptr));
		pick = std::rand() % 3;
		if (pick == 0)
			pb_msg("I don't get your giberish. Speak clearly.", 1);
		else if (pick == 1)
			pb_msg("You're talkin' nonsense. You know what I want. Give it to me.", 1);
		else
			pb_msg("What is it with you today ? You can barely put a word in front of the other.", 1);
	}
	return (0);
}

int	main(void)
{
	PhoneBook	pb;
	int		request_exit;
//	Contact		c1;
//	std::string	entry;

	request_exit = 0;
	display_intro_msg();
	while (!request_exit)
		if (prompt_user(pb) < 0)
			request_exit = 1;

/*
	std::cout << "Enter contact's first name : ";
	std::cin >> entry;
	c1.setFirstName(entry);
	std::cout << "contact first name entered : " << c1.getFirstName() << std::endl;
	std::cout << "contact last name NOT entered : " << c1.getLastName() << std::endl;
	c1.setIsInit();
*/
	return (0);
}
