/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:30:32 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/31 07:06:34 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int N) : N(N), vector(0)
{
}

Span::~Span()
{
}

Span::Span(const Span &span)
{
	*this = span;
}

Span &Span::operator=(const Span &span)
{
	N = span.N;
	vector = span.vector;
	return (*this);
}

void Span::addNumber(int newNumber)
{
	if (this->vector.size() == N)
		throw Span::OverflowException();
	this->vector.push_back(newNumber);
}

void Span::iterAddNumber(unsigned int quantity)
{
	srand(time(NULL));
	try
	{
		for (unsigned int i = 0; i < quantity; i += 1)
			this->addNumber(rand());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int Span::longestSpan()
{
	if (vector.size() < 2)
		throw Span::UnfilledException();
	int min, max;
	min = *std::min_element(vector.begin(), vector.end());
	max = *std::max_element(vector.begin(), vector.end());
	return (max - min);
}

int Span::shortestSpan()
{
	int	min;
	int	distance;

	if (vector.size() < 2)
		throw Span::UnfilledException();
	min = INT_MAX;
	for (size_t i = 0; i < vector.size(); ++i)
	{
		for (size_t j = i + 1; j < vector.size(); ++j)
		{
			distance = std::abs(vector[i] - vector[j]);
			if (distance < min)
			{
				min = distance;
			}
		}
	}
	return (min);
}


void Span::print()
{
	std::vector<int> v = this->vector;
	std::vector<int>::iterator i;

	std::cout << "Vector = ";
	for (i = v.begin(); i != v.end(); i += 1)
		std::cout << *i << " ";
	std::cout << std::endl;
}