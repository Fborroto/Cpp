/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:42:41 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:57:30 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Bau bau" << std::endl;
}

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor called " << std::endl;
}

Dog::Dog( const Dog& dog ) : Animal("Dog")
{
    *this = dog;
    std::cout << "Dog copy Constructor called" << std::endl;
}

Dog&   Dog::operator=( const Dog& dog ) {
    this->type = dog.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Decostrutor called" << std::endl;
}