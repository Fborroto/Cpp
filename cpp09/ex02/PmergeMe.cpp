/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:48:34 by fborroto          #+#    #+#             */
/*   Updated: 2024/11/13 03:37:22 by fborroto         ###   ########.fr       */
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
            std::cout << sequence[i] << (i < sequence.size() - 1 ? " " : "\n");
        }

        std::vector<int> vectorData = sequence;
        std::clock_t startVector = std::clock();
        fordJohnsonSort(vectorData);
        std::clock_t endVector = std::clock();

        double vectorTime = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;
        std::cout << "Sorted sequence (std::vector): ";
        for (std::size_t i = 0; i < vectorData.size(); ++i) {
            std::cout << vectorData[i] << (i < vectorData.size() - 1 ? " " : "\n");
        }
        std::cout << "Time taken by merge-insert sort (std::vector): " << vectorTime << " microseconds\n";

        std::deque<int> dequeData(sequence.begin(), sequence.end());
        std::clock_t startDeque = std::clock();
        fordJohnsonSort(dequeData);
        std::clock_t endDeque = std::clock();

        double dequeTime = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;
        std::cout << "Sorted sequence (std::deque): ";
        for (std::deque<int>::iterator it = dequeData.begin(); it != dequeData.end(); ++it) {
            std::cout << *it << (it + 1 != dequeData.end() ? " " : "\n");
        }
        std::cout << "Time taken by merge-insert sort (std::deque): " << dequeTime << " microseconds\n";

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void PmergeMe::mergeInsertSort(std::vector<int>& sequence) {
    sequence = fordJohnsonSort(sequence);
}

void PmergeMe::mergeInsertSort(std::deque<int>& sequence) {
    sequence = fordJohnsonSort(sequence);
}

std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int>& sequence) {
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

    mainChain = fordJohnsonSort(mainChain);

    for (std::size_t i = 0; i < smaller.size(); ++i) {
        insertIntoMainChain(mainChain, smaller[i]);
    }

    return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonSort(const std::deque<int>& sequence) {
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

    mainChain = fordJohnsonSort(mainChain);

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
