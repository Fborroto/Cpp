/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:06:33 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:57:03 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
    
    public:
        Cat();
        Cat(std::string type);

        ~Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        
        void makeSound() const;
};

#endif