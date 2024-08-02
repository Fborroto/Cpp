/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 06:07:49 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int	main(void)
{
	int a[] = {1, 2 , 3, 4};
	float b[] = {1.1, 2.2, 3.3, 4.4};
	std::string c[] = {"UA", "ciao", "ciao2", "eo"};
	size_t n = 4;
	iter(a, n, &printElement);
	iter(b, n, &printElement);
	iter(c, n, &printElement);
	
	return 0;
}
