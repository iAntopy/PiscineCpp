/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:36:39 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/22 21:39:09 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GrandParent.hpp"
#include <iostream>

int main(void)
{
    Child   c;
    Parent1 p1;
    Parent2 p2;

    std::cout << c.getHP() << std::endl;
    std::cout << p1.getHP() << std::endl;
    std::cout << p2.getHP() << std::endl;
    return (0);
}