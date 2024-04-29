/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:54:18 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 07:00:14 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "Cat Type: " << cat->getType() << std::endl;
	std::cout << "Dog Type: " << dog->getType() << std::endl;

	delete dog;
	delete cat;
    
	Dog basic;
	{
		Dog tmp = basic;
        std::cout << std::endl << "----------end of tmp BasicDog scope--------" << std::endl;
	}

	Cat basicCat;
	{
		Cat tmp = basicCat;
        std::cout << std::endl << "----------end of tmp BasicCat scope--------" << std::endl;
	}
    
      std::cout << std::endl << "----------Array 10 animals--------" << std::endl;
    Animal  *animals[10];

    for (size_t i = 0; i < 10; i++)
    {
        if (i < (10 / 2))
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        delete animals[i];
    }
    std::cout << std::endl << "----------end of basicDog and basicCat scope--------" << std::endl;
}