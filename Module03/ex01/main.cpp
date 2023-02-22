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

int main(void)
{
    ScavTrap    clap1;
    ScavTrap    clap2("Georgie");
    ScavTrap    clap3;

    clap3 = clap2;

    for (int i=0; i < 52; i++)
        clap1.attack("Simbadboy");

    for (int i=0; i < 7; i++)
        clap2.takeDamage(2);
    clap2.attack("Dingleberry");
    clap1.beRepaired(1);
    clap2.beRepaired(1);
    clap3.beRepaired(1);

    clap1.guardGate();
    clap2.guardGate();
    clap3.takeDamage(999);
    clap3.guardGate();
    return (0);
}
