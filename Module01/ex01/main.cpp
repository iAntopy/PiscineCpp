/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:55:03 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/17 00:27:23 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    Zombie  *zs;

    zs = zombieHorde(5, "Mumbo Jumbo");

    for (int i=0; i < 5; i++)
        zs[i].annonce();
            
    delete[] zs;
    zs = NULL;
    return (0);
}