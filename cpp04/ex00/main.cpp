/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:54:18 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 06:17:40 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main( void )
{
    std::cout << "-Animal with virtual function member makeSound" << std::endl;

    const Animal* baseAnimal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Cat Type: " << cat->getType() << std::endl;
    std::cout << "Dog Type: " << dog->getType() << std::endl;
    std::cout << "baseAnimal Type: " << baseAnimal->getType() << std::endl;
    
    dog->makeSound();
    cat->makeSound();
    baseAnimal->makeSound();

    delete  baseAnimal;
    delete  dog;
    delete  cat;

    std::cout << std::endl << "-Wrong Animal without virtual function member makeSound" << std::endl;

    const WrongAnimal *wrong = new WrongAnimal();
    const WrongCat *wrongCat = new WrongCat();
    const WrongAnimal *wrongCat2 = new WrongCat();

    std::cout << "Wrong Type: " << wrong->getType() <<  std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() <<  std::endl;
    std::cout << "WrongCat2 Type: " << wrongCat->getType() <<  std::endl;
    wrong->makeSound();
    wrongCat->makeSound();
    wrongCat2->makeSound();
    
    delete  wrongCat;
    delete  wrongCat2;
    delete  wrong;
}