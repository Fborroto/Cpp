/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:13:30 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 06:45:57 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "miao" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat copy operation" << std::endl;
	if (this != &cat)
	{
		this->type = cat.type;
		this->brain = new Brain(*cat.brain);
	}
	return (*this);
}

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called " << std::endl;
    this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat decostrutor called, brain deleted" << std::endl;
}