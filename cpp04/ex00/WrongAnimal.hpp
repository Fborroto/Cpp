/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:45:03 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:58:06 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal( void );
    WrongAnimal( std::string type );
    ~WrongAnimal( void );

    WrongAnimal( const WrongAnimal& wrongAnimal );
    WrongAnimal& operator=( const WrongAnimal& wrongAnimal );

    void            makeSound() const;
    std::string     getType() const; 
};

#endif