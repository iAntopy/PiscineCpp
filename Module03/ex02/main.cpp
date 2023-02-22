/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:34:21 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/22 01:34:21 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ScavTrap    clap1;
    ScavTrap    clap2("Georgie");
    ScavTrap    clap3;
    clap3 = clap2;

    for (int i=0; i < 5; i++)
        clap1.attack("Simbadboy");

    clap2.attack("Dingleberry");
    clap1.beRepaired(1);
    clap2.beRepaired(1);
    clap3.beRepaired(1);

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

    return (0);
}
