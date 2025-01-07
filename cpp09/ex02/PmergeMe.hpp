/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2025/01/07 14:50:14 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <iterator>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

   	void run(int argc, char** argv);

private:
    std::vector<int> parseInput(const std::string& inputString);
    void mergeInsertSort(std::vector<int>& sequence);
    void mergeInsertSort(std::deque<int>& sequence);

    std::vector<int> mergeInseritonSort(const std::vector<int>& sequence);
    std::deque<int> mergeInseritonSort(const std::deque<int>& sequence);

    void divideAndSort(std::vector<std::vector<std::vector<int> > >& groups);
    
    void insertIntoMainChain(std::vector<int>& mainChain, int value);
    int jacobFormula(int k);
    
    void swapGroups(std::vector<int>& container, size_t leftStart, size_t rightStart, size_t groupSize);
    void fordJohnson(std::vector<int>& container, size_t groupSize);
    void swapGroups(std::deque<int>& container, size_t leftStart, size_t rightStart, size_t groupSize);
    void fordJohnson(std::deque<int>& container, size_t groupSize);
    
    void insertIntoMainChain(std::deque<int>& mainChain, int value);
		class BadInput : public std::exception
	{
		public:
		char const *what() const throw()
		{
			return ("Error: bad input");
		}
	};
};

#endif
