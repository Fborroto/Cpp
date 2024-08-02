/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:38 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 17:03:28 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;

    data.nb = 11;
    data.string = "prova";
    
	uintptr_t uintptr = Serializer::serialize(&data);
	std::cout << "intPtr: " << uintptr << std::endl;
    
	Data* ptr = Serializer::deserialize(uintptr);
	std::cout << "Ptr: " << ptr << std::endl;

	std::cout << "Data: " << ptr->string << " " << ptr->nb << std::endl;

	return 0;

}