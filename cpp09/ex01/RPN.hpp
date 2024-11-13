/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/11/11 23:57:43 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>


# include <cstdlib>
# include <exception>
# include <fstream>
# include <iomanip>
# include <iostream>

class RPN
{
  private:

  public:
	RPN();
	~RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);

    long long evaluateRPN(const std::string& expression);
    bool isNumber(const std::string& token);
    int stringToInt(const std::string& str);
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



