/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:43:20 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/29 21:03:42 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
void ft_print(std::string str)
{
    size_t i = 11;

    i = 11;
    if (str.size() > 10)
    {
        for (size_t j = 0; j < 9; j++)
            std::cout << str[j];
        std::cout << ".";
    }
    else
    {
        while (--i - str.size())
            std::cout << " ";
        std::cout << str;
    }
}

void PhoneBook::ft_add(Contact contact)
{
    size_t i = 0;
    while (i < 8)
    {
        if (i == 7 && !(this->contacts[i].index == ""))
        {
            for (size_t j = 0; j < 7; j++)
            {
                this->contacts[j] = this->contacts[j + 1];
                this->contacts[j].index = j + '0';
            }
            this->contacts[i] = contact;
        }
        if (this->contacts[i].index == "")
        {
            this->contacts[i] = contact;
            this->contacts[i].index += i + '0';
            break;
        }
        i++;
    }
    return;
}
void PhoneBook::ft_search()
{
    if (!(this->contacts[0].index == ""))
    {
            ft_print("index");
            std::cout << "|";
            ft_print("name");
            std::cout << "|";
            ft_print("lastname");
            std::cout << "|";
            ft_print("nickname");
            std::cout << "|\n";

        for (int index = 0; index <= 7; index++)
        {
            if (!(this->contacts[index].index == ""))
            {
                ft_print(this->contacts[index].index);
                std::cout << "|";
                ft_print(this->contacts[index].firstname);
                std::cout << "|";
                ft_print(this->contacts[index].lastname);
                std::cout << "|";
                ft_print(this->contacts[index].nickname);
                std::cout << "|\n";
            }
        }
        std::string input;
        std::cout << "search for index: ";
        std::cin >> input;
        int i = atoi(input.c_str());
        if (!(this->contacts[i].index == ""))
        {
            ft_print("index");
            std::cout << "|";
            ft_print(this->contacts[i].index);
            std::cout << "|\n";
             ft_print("name");
            std::cout << "|";
            ft_print(this->contacts[i].firstname);
            std::cout << "|\n";
             ft_print("lastname");
            std::cout << "|";
            ft_print(this->contacts[i].lastname);
            std::cout << "|\n";
             ft_print("nickname");
            std::cout << "|";
            ft_print(this->contacts[i].nickname);
            std::cout << "|";
        }
        else
            std::cout << "Empty or non existing contact index";
    }
    else
        std::cout << "Empty Contact list";
}

void PhoneBook::ft_exit()
{
    exit(EXIT_SUCCESS);
}