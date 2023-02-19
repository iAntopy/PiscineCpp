/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:25:54 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/18 23:14:42 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	std::string filter;

	filter.clear();
	if (argc > 1)
		filter = argv[1];

	Harl        h(filter);

	h.complain("ERROR");
	return (0);
}