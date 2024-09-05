/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/09/05 07:00:57 by fborroto         ###   ########.fr       */
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


    std::ifstream exchangeDatabase("./data.csv", std::ifstream::in);
	if (!exchangeDatabase.is_open())
	{
		std::cerr << "Error: could not open data.csv file\n";
		return (1);
	}

	BitcoinExchange exchanger;
	
	
	return (0);
}
