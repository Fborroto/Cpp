/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:34:37 by fborroto          #+#    #+#             */
/*   Updated: 2023/12/02 16:44:19 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    std::string input;
    Contact contact;
    PhoneBook phonebook;

    while (1)
    {
        std::cin >> input;
        if (input == "ADD")
        {
            std::cin >> contact.firstname;
            std::cin >> contact.lastname;
            std::cin >> contact.nickname;
            std::cin >> contact.phonenumber;
            std::cin >> contact.darkest_secret;
            phonebook.ft_add(contact);
            std::cout << "fatto!\n";
        }
        if (input == "EXIT")
        {
            phonebook.ft_exit();
        }
        if (input == "SEARCH")
        {
            phonebook.ft_search();
            std::cout << "\nfatto!\n";
        }
    }
}