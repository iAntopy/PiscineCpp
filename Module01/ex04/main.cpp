/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:56:17 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 20:22:05 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	replace_substring_in_file(std::ifstream& f1, std::ofstream& f2, \
	std::string& s1, std::string& s2)
{
	std::string			line;
	size_t				pos;

	while (std::getline(f1, line))
	{
		pos = line.find(s1);
		while (!s1.empty() && pos != std::string::npos)
		{
			f2 << line.substr(0, pos);
			f2 << s2;
			line = line.substr(pos + s1.length());
			pos = line.find(s1);
		}
		f2 << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		new_filename;
	std::ifstream	file1;
	std::ofstream	file2;

	if (argc != 4)
	{
		std::cerr << "ERROR :: Wrong nb of arguments.";
		std::cerr << " Provide a filename, a string to replace in the file and its replacement string" << std::endl;
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	if (filename.empty())
	{
		std::cerr << "ERROR :: No file provided" << std::endl;
		return (EXIT_FAILURE);
	}
	new_filename = filename + ".replace";
	file1.open(filename);
	if (!file1)
	{
		std::cerr << "Could not open file : " << filename << std::endl;
		return (EXIT_FAILURE);
	}
	file2.open(new_filename);
	if (!file2)
	{
		file1.close();
		std::cerr << "Could not open or create file : " << new_filename << std::endl;
		return (EXIT_FAILURE);
	}
	replace_substring_in_file(file1, file2, s1, s2);
	file1.close();
	file2.close();
	return (0);
}