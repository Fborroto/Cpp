/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:28 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 16:42:38 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <string>
#include <sstream>

enum		TYPE
{
	INT,
	CHAR,
	DOUBLE,
	FLOAT,
	PSEUDO,
	NONE
};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &scalar)
{
    *this = scalar;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &scalar)
{
    (void)scalar;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    
}

int	ft_stoi(const std::string &str)
{
	int	num;

	std::stringstream ss(str);
	ss >> num;
	return (num);
}

int	ft_stoll(const std::string &str)
{
	long long	num;

	std::stringstream ss(str);
	ss >> num;
	return (num);
}

float	ft_stof(const std::string &str)
{
	float	num;

	std::stringstream ss(str);
	ss >> num;
	return (num);
}

double	ft_stod(const std::string &str)
{
	double	num;

	std::stringstream ss(str);
	ss >> num;
	return (num);
}

static bool	isChar(std::string input)
{
	if (!isdigit(input[0]) && input.length() == 1)
		return (true);
	return (false);
}

static bool	isInt(std::string input)
{
	size_t		i;
	long long	tmp;

	i = 0;
	if (input.length() > 11 || (input.length() == 11 && (input[0] != '+'
				|| input[0] != '-')))
		return (false);
	if (input[0] == '+' || input[0] == '-')
	{
		if (!input[1] || !isdigit(input[1]))
			return (false);
		i++;
	}
	while (i < input.length())
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	tmp = ft_stoll(input);
	if (tmp >= INT_MIN && tmp <= INT_MAX)
		return (true);
	return (false);
}

static bool	isFloat(std::string input)
{
	size_t	i;
	int		foundDot;

	i = 0;
	foundDot = 0;
	if (input[input.length() - 1] != 'f')
		return (false);
	while (i < input.length() - 1)
	{
		if (input[i] == '.')
			foundDot++;
		else if (!isdigit(input[i]))
			return (false);
		i++;
	}
	if (foundDot != 1)
		return (false);
	return (true);
}

static bool	isDouble(std::string input)
{
	size_t	i;
	int		foundDot;

	i = 0;
	foundDot = 0;
	while (i < input.length())
	{
		if (input[i] == '.')
			foundDot++;
		else if (!isdigit(input[i]))
			return (false);
		i++;
	}
	if (foundDot != 1)
		return false;
	return true;
}

static bool	isPseudoLiteral(std::string input)
{
	if (input.compare("inf") == 0 || input.compare("-inff") == 0
		|| input.compare("-inf") == 0 || input.compare("+inf") == 0
		|| input.compare("nan") == 0 || input.compare("inff") == 0
		|| input.compare("+inff") == 0)
		return true;
	return false;
}

static TYPE	getType(std::string input)
{
	if (isChar(input))
		return CHAR;
	if (isInt(input))
		return INT;
	if (isFloat(input))
		return FLOAT;
	if (isDouble(input))
		return DOUBLE;
	if (isPseudoLiteral(input))
		return PSEUDO;
	return NONE;
}

static void	printFloat(float num)
{
	std::cout << "float: " << num;
	if (num - static_cast<int>(num) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void	printDouble(double num)
{
	std::cout << "double: " << num;
	if (num - static_cast<int>(num) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

static void	printChar(char input)
{
	if (input >= 32 && input <= 126)
		std::cout << "char : '" << input << "'" << std::endl;
	else
		std::cout << "char : "
					<< "Non displayable" << std::endl;
}
static void	printInt(int input)
{
	std::cout << "int: " << input << std::endl;
}
static void	convertInt(int input)
{
	if (input >= 0 && input <= 255)
		printChar(input);
	else
		std::cout << "char : "
					<< "impossible" << std::endl;
	printInt(input);
	printFloat(static_cast<float>(input));
	printDouble(static_cast<double>(input));
}

static void	convertFloat(float input)
{
	if (input >= 0 || input <= 255)
		printChar(static_cast<char>(input));
	else
		std::cout << "char : "
					<< "impossible" << std::endl;
	printInt(static_cast<int>(input));
	printFloat(input);
	printDouble(static_cast<double>(input));
}

static void	convertDouble(double input)
{
	if (input >= 0 || input <= 255)
		printChar(static_cast<char>(input));
	else
		std::cout << "char : "
					<< "impossible" << std::endl;
	printInt(static_cast<int>(input));
	printFloat(static_cast<float>(input));
	printDouble(input);
}

static void	convertChar(char input)
{
	printChar(input);
	printInt(static_cast<int>(input));
	printFloat(static_cast<float>(input));
	printDouble(static_cast<double>(input));
}

static void	convertPseudo(std::string input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input.compare("-inff") == 0 || input.compare("+inff") == 0
		|| input.compare("inff") == 0)
		std::cout << "float: " << input << std::endl;
	else
		std::cout << "float: " << input << "f" << std::endl;
	if (input.compare("-inff") == 0 || input.compare("+inff") == 0
		|| input.compare("inff") == 0)
		std::cout << "double: " << input.substr(0, input.length()
			- 1) << std::endl;
	else
		std::cout << "double: " << input << std::endl;
}

void ScalarConverter::scalarConvert(std::string input)
{
	switch (getType(input))
	{
	case CHAR:
		convertChar(input[0]);
		break ;
	case INT:
		convertInt(ft_stoi(input));
		break ;
	case FLOAT:
		convertFloat(ft_stof(input));
		break ;
	case DOUBLE:
		convertDouble(ft_stod(input));
		break ;
	case PSEUDO:
		convertPseudo(input);
		break ;
	default:
		std::cout << "invalid input \n";
		break ;
	}
}