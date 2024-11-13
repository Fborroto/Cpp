/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/11/13 01:56:15 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: You must provide at least one number as argument." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;
    pmergeMe.run(argc, argv);
    return 0;
}
