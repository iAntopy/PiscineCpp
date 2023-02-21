/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:41:35 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/19 19:41:35 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void	triangle_test_1(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(4.0f, 3.0f);
	Point	c(4.0f, 0.0f);

	Point	probe1 = Point(0.0f, 0.0f);
	bool	is_inside = bsp(a, b, c, probe1);
	bool	correct_result = false;

	std::cout << std::boolalpha;
	std::cout << "TRIANGLE 1 ABC : " << a << b << c << std::endl;
	std::cout << "	test Point 1: " << probe1 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl;

	Point	probe2(100.0f, 100.0f);
	is_inside = bsp(a, b, c, probe2);
	correct_result = false;

	std::cout << "	test Point 2: " << probe2 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl;

	Point	probe3(3.0f, 2.0f);
	is_inside = bsp(a, b, c, probe3);
	correct_result = true;

	std::cout << "	test Point 3: " << probe3 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl << std::endl;

}

void	triangle_test_2(void)
{
	Point	a(-1.0f, 0.0f);
	Point	b(-5.0f, 2.5f);
	Point	c(-5.0f, -2.5f);

	Point	probe1 = Point(0.0f, 0.0f);
	bool	is_inside = bsp(a, b, c, probe1);
	bool	correct_result = false;

	std::cout << std::boolalpha;
	std::cout << "TRIANGLE 2 ABC : " << a << b << c << std::endl;
	std::cout << "	test Point 1: " << probe1 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl;

	Point	probe2(-1.0f, 0.0f);
	is_inside = bsp(a, b, c, probe2);
	correct_result = false;

	std::cout << "	test Point 2: " << probe2 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl;

	Point	probe3(-4.0f, 1.0f);
	is_inside = bsp(a, b, c, probe3);
	correct_result = true;

	std::cout << "	test Point 3: " << probe3 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl << std::endl;
	
}

void	triangle_test_3(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 5.0f);
	Point	c(5.0f, 0.0f);

	Point	probe1 = Point(1.0f, 1.0f);
	bool	is_inside = bsp(a, b, c, probe1);
	bool	correct_result = false;

	std::cout << std::boolalpha;
	std::cout << "TRIANGLE 3 ABC : " << a << b << c << std::endl;
	std::cout << "	test Point 1: " << probe1 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl;

	Point	probe2(0.99f, 1.0f);
	is_inside = bsp(a, b, c, probe2);
	correct_result = false;

	std::cout << "	test Point 2 : " << probe2 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl;

	Point	probe3(1.01f, 1.0f);
	is_inside = bsp(a, b, c, probe3);
	correct_result = true;

	std::cout << "	test Point 3 : " << probe3 << std::endl;
	std::cout << "	bsp test returned : " << is_inside << ", should be : " << correct_result << std::endl;

}

int main( void )
{
	triangle_test_1();
	triangle_test_2();
	triangle_test_3();
	return (0);
}
