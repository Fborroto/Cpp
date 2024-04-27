/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:00:28 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/27 22:01:44 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename) : inFile(filename)
{
 this->outFile = this->inFile + ".replace";   
}

Sed::~Sed(void)
{
}

void Sed::ft_replace(std::string input, std::string output)  
{
    std::ifstream   inFileStream(this->inFile.c_str());
    
    if(inFileStream.is_open())
    {
        std::string str;
        std::ofstream   outFileStream(this->outFile.c_str());
         while (std::getline(inFileStream, str)) 
			{
				size_t	posOut = str.find(input);
				if(posOut != std::string::npos)
				{
					str.erase(posOut, input.length());
					str.insert(posOut, output);
				}
				outFileStream << str<< "\n";
			}
                outFileStream.close();
                inFileStream.close();
    }
    else {
        std::cerr << "Failed to open file" << std::endl;
    }
}
