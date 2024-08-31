/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/29 19:01:13 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main(void)
{
	std::vector<int> container;
	
	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}
	std::cout << "container values are:" << std::endl;
	for( size_t i = 0; i < container.size() ; i++)
	{
		std::cout << container[i] << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
	
	if(easyfind(container, 5) == true){
		std::cout << "value '5' found"<< std::endl;
	}
	else
		std::cout << "value '5' not found"<< std::endl;
	
	
	if(easyfind(container, 11) == true){
		std::cout << "value '11' found"<< std::endl;
	}
	else
		std::cout << "value '11' not found"<< std::endl;
		
	return (0);
}
