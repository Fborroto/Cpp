/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:30:32 by fborroto          #+#    #+#             */
/*   Updated: 2024/10/05 15:18:02 by fborroto         ###   ########.fr       */
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

void Span::iterAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + vector.size() > N)
        throw Span::OverflowException();
    vector.insert(vector.end(), begin, end);
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
	std::vector<int> temp = vector;
	std::sort(temp.begin(), temp.end());
	for (size_t i = 1; i < temp.size(); ++i)
	{
		distance = temp[i] - temp[i - 1];
		min = std::min(min, distance);
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