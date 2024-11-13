/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/11/13 02:24:24 by fborroto         ###   ########.fr       */
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

    std::vector<int> fordJohnsonSort(const std::vector<int>& sequence);
    std::deque<int> fordJohnsonSort(const std::deque<int>& sequence);

    void insertIntoMainChain(std::vector<int>& mainChain, int value);
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
