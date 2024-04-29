/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:50:52 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 14:19:25 by fborroto         ###   ########.fr       */
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

//6 Comparison operators //

bool    Fixed::operator>( const Fixed &fi ) const {
    return this->getRawBits() > fi.getRawBits();
}

bool    Fixed::operator<( const Fixed &fi ) const {
    return this->getRawBits() < fi.getRawBits();
}

bool    Fixed::operator>=( const Fixed &fi ) const {
    return this->getRawBits() >= fi.getRawBits();
}

bool   Fixed::operator<=( const Fixed &fi ) const {
    return this->getRawBits() <= fi.getRawBits();
}

bool  Fixed::operator==( const Fixed &fi ) const {
    return this->getRawBits() == fi.getRawBits();
}

bool    Fixed::operator!=( const Fixed &fi ) const {
    return this->getRawBits() != fi.getRawBits();
}
// 4 Arithmetic operators //

Fixed   Fixed::operator+( const Fixed &fi ) const {
    return Fixed( this->toFloat() + fi.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &fi ) const {
    return Fixed( this->toFloat() - fi.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &fi ) const {
    return Fixed( this->toFloat() * fi.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &fi ) const {
    return Fixed( this->toFloat() / fi.toFloat() );
}

//Increment/Decrement operators//

Fixed&   Fixed::operator++() {
    ++this->value;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp.value = this->value++;
    return tmp;
}

Fixed& Fixed::operator--() {
    --this->value;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp.value = this->value--;
    return tmp;
}

//Max and Min//

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}