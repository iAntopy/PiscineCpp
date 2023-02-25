/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:34:21 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/24 22:29:50 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
//#include "FragTrap.hpp"

int main(void)
{
    DiamondTrap    d1;
    DiamondTrap    d2("Georgie");
    DiamondTrap    d3;
    d3 = d2;

    std::cout << "d1 : "<< d1 << std::endl;
    std::cout << "d2 : "<< d2 << std::endl;
    std::cout << "d3 : "<< d3 << std::endl;

    d1.attack("Poverty");
    d1.guardGate();
    d3.highFivesGuys();
    d2.whoAmI();    
/*
    for (int i=0; i < 5; i++)
        d1.attack("Simbadboy");

    d2.attack("Dingleberry");
    d1.beRepaired(1);
    d2.beRepaired(1);
    d3.beRepaired(1);

    clap1.guardGate();
    clap2.guardGate();
    clap3.takeDamage(999);
    clap3.guardGate();



    FragTrap    frag1;
    FragTrap    frag2("Bango");
    FragTrap    frag3;
    frag3 = frag2;

    frag1.attack("Jimothy");
    frag2.takeDamage(999);
    for (int i=0; i < 102; i++)
        frag3.attack("Mambossa");
    
    frag1.highFivesGuys();
    frag2.highFivesGuys();
    frag3.highFivesGuys();
*/
    return (0);
}
