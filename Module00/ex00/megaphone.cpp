/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:51:11 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/12 04:17:14 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc ; i++)
		{
			std::string	s = argv[i];
			for (int j = 0; s[j]; j++)
				s[j] = std::toupper(s[j]);
			std::cout << s;
		}
		std::cout << std::endl;
	}
	return (0);
}
