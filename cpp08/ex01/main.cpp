/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/10/05 15:29:18 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "-----------------------------" << std::endl;

			Span sp2 = Span(100000);
			std::vector<int> addnumbers;

			for (size_t i = 0; i < 10; i++ )
			{
				addnumbers.push_back(i);
			}

			sp2.iterAddNumber(addnumbers.begin(), addnumbers.end());
			sp2.print();
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
			Span sp3 = Span(4);
			sp3.iterAddNumber(addnumbers.begin(), addnumbers.end());
			sp3.print();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}