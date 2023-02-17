/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:43:17 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/16 23:20:25 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <string>

class Zombie
{
    private:
        std::string _name;
        
    public:
        Zombie(std::string& name);
        ~Zombie();
        
        void    annonce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif