/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:47:02 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 06:02:30 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("DefaultWrongAnimal")
{
	std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal " << this->type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &wrongAnimal)
	{
		this->type = wrongAnimal.type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
