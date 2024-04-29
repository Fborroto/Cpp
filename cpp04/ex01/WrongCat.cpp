/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:50:05 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:58:17 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& wrongCat ) : WrongAnimal("WrongCat")
{
    *this = wrongCat;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&   WrongCat::operator=( const WrongCat& wrongCat ) {
    this->type = wrongCat.type;
    return *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound()  const
{
    std::cout << "miao" << std::endl;
}