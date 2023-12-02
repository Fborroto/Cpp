/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:44:55 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/29 19:45:19 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <cstring>
# include <stdlib.h>
# include "Contact.hpp"

class PhoneBook
{
public:
        Contact contacts[8];
        void ft_add(Contact contact);
        void ft_search();
        void ft_exit();
}; 
#endif