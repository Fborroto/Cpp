/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:30:32 by fborroto          #+#    #+#             */
/*   Updated: 2024/11/12 11:33:59 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"


RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &RPN)
{
	*this = RPN;
}

RPN &RPN::operator=(const RPN &RPN)
{
    (void)RPN;
	return (*this); 
}

int RPN::stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int number;
    ss >> number;

    if (ss.fail()) {
         throw BadInput();
    }

    return number;
}

bool RPN::isNumber(const std::string& token) {
    for (std::string::const_iterator it = token.begin(); it != token.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

long long RPN::evaluateRPN(const std::string& expression) {
    std::stack<int> stack;  
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
            if (isNumber(token)) {
                stack.push(stringToInt(token));
        } else {
            if (stack.size() < 2) {
                throw BadInput();
            }

            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            std::cout << "Applying operator: " << token << " on " << operand1 << " and " << operand2 << std::endl; // Debug line
            
            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            } else if (token == "/") {
                if (operand2 == 0) {
                    throw std::runtime_error("Division by zero");
                }
                stack.push(operand1 / operand2);
            } else {
                throw BadInput();
            }
        }
    }

    if (stack.size() != 1) {
        throw BadInput();
    }

    return stack.top(); 
}

