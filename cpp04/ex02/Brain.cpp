/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:23:18 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 06:25:18 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain decostructor" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain copy called." << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = brain.ideas[i];
		}
	}
	return (*this);
}