/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrandParent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:29:29 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/22 22:53:49 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GRANDPARENT_HPP__
# define __GRANDPARENT_HPP__

class GrandParent
{
	protected:
		int _hp;
		
	public:
		GrandParent(void);
		~GrandParent();

		virtual int getHP(void) const;
};

class Parent1 : virtual public GrandParent
{
	protected:
		int _hp;
		
	public:
		Parent1(void);
		~Parent1();
	
		//virtual int	getHP(void) const;
};

class Parent2 : virtual public GrandParent
{
	protected:
		int _hp;
		
	public:
		Parent2(void);
		~Parent2();
	
		//virtual int	getHP(void) const;
};

class Child : public Parent1, public Parent2
{
	private:
		int _hp;
		
	public:
		Child(void);
		~Child();

		int	getHP(void) const;
};
#endif