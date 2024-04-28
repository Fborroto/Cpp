/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:50:52 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 04:22:38 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	this->value = 0;
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
	std::cout << "getRawBits called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->value = raw;
}

const Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}