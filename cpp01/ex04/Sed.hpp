/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:56:17 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/27 21:46:54 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed
{
   private:
    std::string inFile;
    std::string outFile;
   
   public:
   Sed(std::string filename);
   ~Sed();

   void ft_replace(std::string s1, std::string s2);
};

#endif