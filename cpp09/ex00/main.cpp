/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/11/04 20:01:44 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	std::ifstream input_db(argv[1], std::ifstream::in);
	
	if (argc != 2 || !input_db.is_open())
	{
		std::cerr << "Error: could not open input file\n";
		return (1);
	}




	BitcoinExchange exchanger;
	exchanger.exchangeBitcoin(argv[1]);
	
	return (0);
}
