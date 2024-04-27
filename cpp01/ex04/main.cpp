/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:15:26 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/27 21:39:20 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char**argv)
{
	if (argc == 4)
	{
		Sed replacer(argv[1]);
		replacer.ft_replace(argv[2], argv[3]);
	}
	else
		std::cout << "wrong argument number" << std::endl;
}