/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:38:19 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/16 23:55:37 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *zs = new Zombie[N];
    
    //    zs = new Zombie[N];
    for (int i=0; i < N; i++)
        zs[i].setName(name);
    return (zs);
}