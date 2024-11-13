/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/31 07:21:58 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <climits>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <map>
# include <string>
# include <sstream>

class BitcoinExchange
{
  private:
	std::map<std::string, float> database;

  public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);

	void exchangeBitcoin(std::string file);

	void extractData();
	bool isLeapYear(int year);
	bool isValidDate(int year, int month, int day);
	void checkDate(const std::string &date);
	void checkValue(float value);
	float getDateValue(const std::string& date) const;
	class BadInput : public std::exception
	{
		public:
		char const *what() const throw()
		{
			return ("Error: bad input => ");
		}
	};
	class InvalidNumberNegative : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: not a positive number.");
		}
	};

	class InvalidNumberBig : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: too large number.");
		}
	};
};

#endif