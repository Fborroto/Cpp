/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:50:52 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 05:26:45 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	this->value = 0;
}
Fixed::Fixed(const int &v) : value(v << bits)
{
	std::cout << "int Constructor called" << std::endl;
}

Fixed::Fixed(const float &v) : value(roundf(v * (1 << bits)))
{
	std::cout << "float Constructor called" << std::endl;
}
 Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Decostructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << bits );
}

int     Fixed::toInt( void ) const {
    return this->value >> bits;
}

const Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream &o, Fixed const & in)
{
	o << in.toFloat();
	return o;
}