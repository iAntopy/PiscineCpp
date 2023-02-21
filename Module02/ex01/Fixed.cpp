/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:11:28 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/20 02:11:28 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_frac_nbits = 8;

/*
def to_fixed(f,e):
    a = f* (2**e)
    b = int(round(a))
    if a < 0:
        # next three lines turns b into it's 2's complement.
        b = abs(b)
        b = ~b
        b = b + 1
    return b
*/

static int	float_to_fixed(float const f, int const frac_nBits)
{
	float	t;
	int		res;

	t = f * (1 << frac_nBits);
	res = (int)roundf(t);
	if (t < 0)
	{
		res = -res;
		res = ~res;
		res += 1;
	}
	return (res);
}

/*
x is the input fixed number which is of integer datatype
e is the number of fractional bits for example in Q1.15 e = 15

def to_float(x,e):
    c = abs(x)
    sign = 1 
    if x < 0:
        # convert back from two's complement
        c = x - 1 
        c = ~c
        sign = -1
    f = (1.0 * c) / (2 ** e)
    f = f * sign
    return f
*/

static float	fixed_to_float(int const x, int const frac_nBits)
{
	int		c;
	int		sign;
	float	f;

	c = std::abs(x);
	sign = 1;
	if (x < 0)
	{
		c = x - 1;
		c = ~c;
		sign = -1;
	}
//	f = (float)c;
//	f /= (1 << frac_nBits);
	f = (float)c / (1 << frac_nBits);
	f *= sign;
	return (f);
}

Fixed::Fixed(void) : _n(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const i) : _n(i << this->_frac_nbits) {
	std::cout << "Integer constructor called : " << i << " -> " << this->_n << std::endl;
}

//Fixed::Fixed(float const f) : _n(f * pow2(_frac_nbits)) {
Fixed::Fixed(float const f) : _n(float_to_fixed(f, _frac_nbits)) {
	std::cout << "Float constructor called : " << f << " -> " << _n << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
//	std::cout << "this n : " << _n << std::endl;
//	std::cout << "this frac_nbits : " << _frac_nbits << std::endl;
//	std::cout << "other n : " << other._n << std::endl;
//	std::cout << "other frac_nbits : " << other._frac_nbits << std::endl;
//	std::cout << "internal int before : " << _n << std::endl;
	this->setRawBits(other.getRawBits());
//	std::cout << "after : " << _n << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_n);
}

void     Fixed::setRawBits(int const n)
{
	this->_n = n;
}

int		Fixed::toInt(void) const
{
//	return ((int)roundf(fixed_to_float(_n, _frac_nbits)));

	return (_n >> _frac_nbits);
}

float	Fixed::toFloat(void) const
{
	return (fixed_to_float(_n, _frac_nbits));
}

std::ostream&	operator<<(std::ostream& out, Fixed const& f)
{
	out << f.toFloat();
	return (out);
}