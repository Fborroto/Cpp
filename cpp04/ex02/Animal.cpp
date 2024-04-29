/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:57:01 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:57:17 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("DefaultNameMario")
{
	std::cout << "Animal base class constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal base class constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal base class destructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal base class copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal base class assignment operator called" << std::endl;
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal base class makes sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}