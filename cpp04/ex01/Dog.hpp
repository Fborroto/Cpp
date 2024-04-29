/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:18:27 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 06:41:19 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef DOG_H
# define DOG_H

class Dog : public Animal
{
  private:
	Brain *brain;

  public:
	~Dog(void);
	Dog(void);
	Dog(std::string _type);
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);

	void makeSound() const;
};

#endif