/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:48:34 by fborroto          #+#    #+#             */
/*   Updated: 2025/01/06 18:30:56 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

void PmergeMe::run(int argc, char** argv) {
	try {
		std::vector<int> sequence;
		for (int i = 1; i < argc; ++i) {
			int number = std::atoi(argv[i]);
			if (number <= 0) {
				throw std::runtime_error("Error: Only positive integers are allowed.");
			}
			sequence.push_back(number);
		}

		if (sequence.empty()) {
			throw std::runtime_error("Error: No valid numbers provided.");
		}

		std::cout << "Unsorted sequence: ";
		for (std::size_t i = 0; i < sequence.size(); ++i) {
			std::cout << sequence[i] << (i < sequence.size() - 1 ? " " : "\n\n\n");
		}

		std::vector<int> vectorData = sequence;
		std::clock_t startVector = std::clock();
		vectorData = mergeInseritonSort(vectorData);
		std::clock_t endVector = std::clock();

		double vectorTime = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;
		std::cout << "Sorted sequence (std::vector): ";
		for (std::size_t i = 0; i < vectorData.size(); ++i) {
			std::cout << vectorData[i] << (i < vectorData.size() - 1 ? " " : "\n");
		}
		std::cout << "Time taken by merge-insert sort (std::vector): " << vectorTime << " microseconds\n\n\n";

	// ------------------------------------------------------------------------------------------------------------------------
		std::vector<int> vectorData2 = sequence;
		std::clock_t startVector2 = std::clock();
		fordJohnson(vectorData2, 1);
		std::clock_t endVector2 = std::clock();

		double vectorTime2 = 1000000.0 * (endVector2 - startVector2) / CLOCKS_PER_SEC;
		std::cout << "Sorted sequence (std::vector): ";
		for (std::size_t i = 0; i < vectorData2.size(); ++i) {
			std::cout << vectorData2[i] << (i < vectorData2.size() - 1 ? " " : "\n");
		}
		std::cout << "Time taken by fordJohnson sort (std::vector): " << vectorTime2 << " microseconds\n\n\n";
	// ------------------------------------------------------------------------------------------------------------------------

		
		std::deque<int> dequeData(sequence.begin(), sequence.end());
		std::clock_t startDeque = std::clock();
		mergeInseritonSort(dequeData);
		std::clock_t endDeque = std::clock();

		double dequeTime = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;
		std::cout << "Sorted sequence (std::deque): ";
		for (std::deque<int>::iterator it = dequeData.begin(); it != dequeData.end(); ++it) {
			std::cout << *it << (it + 1 != dequeData.end() ? " " : "\n");
		}
		std::cout << "Time taken by merge-insert sort (std::deque): " << dequeTime << " microseconds\n\n\n";


		// ------------------------------------------------------------------------------------------------------------------------
		std::deque<int> dequeData2(sequence.begin(), sequence.end());
		std::clock_t startDeque2 = std::clock();
		fordJohnson(dequeData2, 1);
		std::clock_t endDeque2 = std::clock();

		double dequeTime2 = 1000000.0 * (endDeque2 - startDeque2) / CLOCKS_PER_SEC;
		std::cout << "Sorted sequence (std::deque): ";
		for (std::deque<int>::iterator it = dequeData2.begin(); it != dequeData2.end(); ++it) {
			std::cout << *it << (it + 1 != dequeData2.end() ? " " : "\n");
		}
		std::cout << "Time taken by FordJohnson sort (std::deque): " << dequeTime2 << " microseconds\n";
   		// ------------------------------------------------------------------------------------------------------------------------
	
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void PmergeMe::mergeInsertSort(std::vector<int>& sequence) {
	sequence = mergeInseritonSort(sequence);
}

void PmergeMe::mergeInsertSort(std::deque<int>& sequence) {
	sequence = mergeInseritonSort(sequence);
}

std::vector<int> PmergeMe::mergeInseritonSort(const std::vector<int>& sequence) {
	if (sequence.size() <= 1) return sequence;

	std::vector<int> mainChain;
	std::vector<int> smaller;

	for (std::size_t i = 0; i + 1 < sequence.size(); i += 2) {
		if (sequence[i] > sequence[i + 1]) {
			mainChain.push_back(sequence[i]);
			smaller.push_back(sequence[i + 1]);
		} else {
			mainChain.push_back(sequence[i + 1]);
			smaller.push_back(sequence[i]);
		}
	}

	if (sequence.size() % 2 != 0) {
		smaller.push_back(sequence.back());
	}

	mainChain = mergeInseritonSort(mainChain);

	for (std::size_t i = 0; i < smaller.size(); ++i) {
		insertIntoMainChain(mainChain, smaller[i]);
	}

	return mainChain;
}

std::deque<int> PmergeMe::mergeInseritonSort(const std::deque<int>& sequence) {
	if (sequence.size() <= 1) return sequence;

	std::deque<int> mainChain;
	std::deque<int> smaller;

	for (std::size_t i = 0; i + 1 < sequence.size(); i += 2) {
		if (sequence[i] > sequence[i + 1]) {
			mainChain.push_back(sequence[i]);
			smaller.push_back(sequence[i + 1]);
		} else {
			mainChain.push_back(sequence[i + 1]);
			smaller.push_back(sequence[i]);
		}
	}

	if (sequence.size() % 2 != 0) {
		smaller.push_back(sequence.back());
	}

	mainChain = mergeInseritonSort(mainChain);

	for (std::deque<int>::const_iterator it = smaller.begin(); it != smaller.end(); ++it) {
		insertIntoMainChain(mainChain, *it);
	}

	return mainChain;
}

void PmergeMe::insertIntoMainChain(std::vector<int>& mainChain, int value) {
	std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(it, value);
}

void PmergeMe::insertIntoMainChain(std::deque<int>& mainChain, int value) {
	std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(it, value);
}










void PmergeMe::swapGroups(std::vector<int>& container, size_t leftStart, size_t rightStart, size_t groupSize) {
		int maxLeft = *std::max_element(container.begin() + leftStart, container.begin() + leftStart + groupSize);
		int maxRight = *std::max_element(container.begin() + rightStart, container.begin() + rightStart + groupSize);

		if (maxLeft > maxRight) {
			for (size_t j = 0; j < groupSize && rightStart + j < container.size(); ++j) {
				std::swap(container[leftStart + j], container[rightStart + j]);
			}
		}
	}


	int PmergeMe::jacobFormula(int k) {
		/* double pow2 = std::pow(2.0, k + 1);
		double powNeg1 = (k % 2 == 0) ? 1 : -1;
		double result = (pow2 + powNeg1) / 3.0;
		return (result >= 0) ? static_cast<int>(result + 0.5) : static_cast<int>(result - 0.5); */

		static const int jacobsthal_num[] = {
			3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763,
			 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621,
			  44739243, 89478485, 178956971, 357913941
		};

		static const int size = sizeof(jacobsthal_num) / sizeof(jacobsthal_num[0]);

		if (k < 0 || k >= size) {
			throw std::out_of_range("Index k is out of range for Jacobsthal sequence.");
		}

		return jacobsthal_num[k];
	}

	struct CompareVectorIterator {
		bool operator()(const std::vector<int>::iterator& a, const std::vector<int>::iterator& b) const {
			return *a < *b;
		}
	};

	void PmergeMe::fordJohnson(std::vector<int>& container, size_t groupSize) {
		size_t size = container.size();
		int pair_units_nbr = size / groupSize;

		if (pair_units_nbr < 2) {
			return;
		}

		for (size_t i = 0; i < size; i += groupSize * 2) {
			size_t leftStart = i;
			size_t rightStart = i + groupSize;

			if (rightStart < size) {
				swapGroups(container, leftStart, rightStart, groupSize);
			}
		}

		fordJohnson(container, groupSize * 2);

			std::vector<std::vector<int>::iterator> main;
			std::vector<std::vector<int>::iterator> pend;

		std::vector<int>::iterator it = container.begin();
		std::advance(it, groupSize - 1);
		main.push_back(it);

		it = container.begin();
		std::advance(it, groupSize * 2 - 1);
		main.push_back(it);

		for (int i = 4; i <= pair_units_nbr; i += 2) {
			it = container.begin();
			std::advance(it, groupSize * (i - 1) - 1);
			pend.push_back(it);

			it = container.begin();
			std::advance(it, groupSize * i - 1);
			main.push_back(it);
		}

		int prev_jacob_number = 1;
		int inserted_count = 0;

		for (int k = 2;; ++k) {
			int curr_jacobsthal = jacobFormula(k);
			int jacobsthal_diff = curr_jacobsthal - prev_jacob_number;

			if (jacobsthal_diff > static_cast<int>(pend.size())) {
				break;
			}

			std::vector<std::vector<int>::iterator>::iterator pend_it = pend.begin() + (jacobsthal_diff - 1);
			std::vector<std::vector<int>::iterator>::iterator bound_it = main.begin() + (curr_jacobsthal + inserted_count);

			while (jacobsthal_diff > 0) {
				std::vector<std::vector<int>::iterator>::iterator idx = std::upper_bound(
					main.begin(), bound_it, *pend_it, CompareVectorIterator());

				main.insert(idx, *pend_it);
				pend.erase(pend_it);
				pend_it = pend.begin() + (jacobsthal_diff - 2);
				--jacobsthal_diff;

				bound_it = main.begin() + (curr_jacobsthal + inserted_count);
			}

			prev_jacob_number = curr_jacobsthal;
			inserted_count += (curr_jacobsthal - prev_jacob_number);
		}
		
		for (size_t i = 0; i < pend.size(); i++)
		{
			std::vector<std::vector<int>::iterator>::iterator it = pend.begin();
			std::advance(it, i);
			std::vector<std::vector<int>::iterator>::iterator top_bound = main.begin();
			std::advance(top_bound, main.size() - pend.size() + i);
			std::vector<std::vector<int>::iterator>::iterator idx =
			std::upper_bound(main.begin(), top_bound, *it, CompareVectorIterator());
			main.insert(idx, *it);
		}

		if(pair_units_nbr % 2 == 1)
		{
			std::vector<int>::iterator it = container.begin();
			std::advance(it, groupSize * (pair_units_nbr - (pair_units_nbr % 2)) + groupSize - 1);
			std::vector<std::vector<int>::iterator>::iterator idx =
			std::upper_bound(main.begin(), main.end(), it, CompareVectorIterator());
			main.insert(idx, it);
		}

		std::vector<int> tmp;	
		tmp.reserve(container.size());
		for (std::vector<std::vector<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
		{
			for(size_t i = 0; i < groupSize; i++)
			{
				std::vector<int>::iterator start = *it;
				std::advance(start, -groupSize + i + 1);
				tmp.insert(tmp.end(), *start);
			}
		}
		std::vector<int>::iterator container_it = container.begin();
		std::vector<int>::iterator tmp_it = tmp.begin();
		while (tmp_it != tmp.end())
		{
			*container_it = *tmp_it;
			container_it++;
			tmp_it++;
		}
	}


	
void PmergeMe::swapGroups(std::deque<int>& container, size_t leftStart, size_t rightStart, size_t groupSize) {
	int maxLeft = *std::max_element(container.begin() + leftStart, container.begin() + leftStart + groupSize);
	int maxRight = *std::max_element(container.begin() + rightStart, container.begin() + rightStart + groupSize);

	if (maxLeft > maxRight) {
		for (size_t j = 0; j < groupSize && rightStart + j < container.size(); ++j) {
			std::swap(container[leftStart + j], container[rightStart + j]);
		}
	}
}


struct CompareDequeIterator {
	bool operator()(const std::deque<int>::iterator& a, const std::deque<int>::iterator& b) const {
		return *a < *b;
	}
};

void PmergeMe::fordJohnson(std::deque<int>& container, size_t groupSize) {
	size_t size = container.size();
	int pair_units_nbr = size / groupSize;

	if (pair_units_nbr < 2) {
		return;
	}

	for (size_t i = 0; i < size; i += groupSize * 2) {
		size_t leftStart = i;
		size_t rightStart = i + groupSize;

		if (rightStart < size) {
			swapGroups(container, leftStart, rightStart, groupSize);
		}
	}

	fordJohnson(container, groupSize * 2);

	std::deque<std::deque<int>::iterator> main;
	std::deque<std::deque<int>::iterator> pend;

	std::deque<int>::iterator it = container.begin();
	std::advance(it, groupSize - 1);
	main.push_back(it);

	it = container.begin();
	std::advance(it, groupSize * 2 - 1);
	main.push_back(it);

	for (int i = 4; i <= pair_units_nbr; i += 2) {
		it = container.begin();
		std::advance(it, groupSize * (i - 1) - 1);
		pend.push_back(it);

		it = container.begin();
		std::advance(it, groupSize * i - 1);
		main.push_back(it);
	}

	int prev_jacob_number = 1;
	int inserted_count = 0;

	for (int k = 2;; ++k) {
		int curr_jacobsthal = jacobFormula(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacob_number;

		if (jacobsthal_diff > static_cast<int>(pend.size())) {
			break;
		}

		std::deque<std::deque<int>::iterator>::iterator pend_it = pend.begin() + (jacobsthal_diff - 1);
		std::deque<std::deque<int>::iterator>::iterator bound_it = main.begin() + (curr_jacobsthal + inserted_count);

		while (jacobsthal_diff > 0) {
			std::deque<std::deque<int>::iterator>::iterator idx = std::upper_bound(
				main.begin(), bound_it, *pend_it, CompareDequeIterator());

			main.insert(idx, *pend_it);
			pend.erase(pend_it);
			pend_it = pend.begin() + (jacobsthal_diff - 2);
			--jacobsthal_diff;

			bound_it = main.begin() + (curr_jacobsthal + inserted_count);
		}

		prev_jacob_number = curr_jacobsthal;
		inserted_count += (curr_jacobsthal - prev_jacob_number);
	}

	for (size_t i = 0; i < pend.size(); i++)
	{
		std::deque<std::deque<int>::iterator>::iterator it = pend.begin();
		std::advance(it, i);
		std::deque<std::deque<int>::iterator>::iterator top_bound = main.begin();
		std::advance(top_bound, main.size() - pend.size() + i);
		std::deque<std::deque<int>::iterator>::iterator idx =
		std::upper_bound(main.begin(), top_bound, *it, CompareDequeIterator());
		main.insert(idx, *it);
	}

	if(pair_units_nbr % 2 == 1)
	{
		std::deque<int>::iterator it = container.begin();
		std::advance(it, groupSize * (pair_units_nbr - (pair_units_nbr % 2)) + groupSize - 1);
		std::deque<std::deque<int>::iterator>::iterator idx =
		std::upper_bound(main.begin(), main.end(), it, CompareDequeIterator());
		main.insert(idx, it);
	}

	std::deque<int> tmp;    
	for (std::deque<std::deque<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for(size_t i = 0; i < groupSize; i++)
		{
			std::deque<int>::iterator start = *it;
			std::advance(start, -groupSize + i + 1);
			tmp.push_back(*start);
		}
	}

	std::deque<int>::iterator container_it = container.begin();
	std::deque<int>::iterator tmp_it = tmp.begin();
	while (tmp_it != tmp.end())
	{
		*container_it = *tmp_it;
		container_it++;
		tmp_it++;
	}
}