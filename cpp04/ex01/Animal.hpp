/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:38:35 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 06:30:11 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);

        virtual ~Animal();
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        virtual void makeSound() const;
        std::string getType() const;
};

#endif