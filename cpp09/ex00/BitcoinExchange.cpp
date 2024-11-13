/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:30:32 by fborroto          #+#    #+#             */
/*   Updated: 2024/11/09 00:17:16 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange)
{
	*this = bitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange)
{
	database = bitcoinExchange.database;
	return (*this);
}

void BitcoinExchange::extractData()
{
	bool	firstLineChecked;
	float	value;

	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file." << std::endl;
		exit(1);
	}
	std::string line;
	firstLineChecked = false;
	while (std::getline(file, line))
	{
		if (!firstLineChecked)
		{
			if (line == "date,exchange_rate")
			{
				firstLineChecked = true;
				continue ;
			}
			else if (line.empty())
				continue ;
			else
				firstLineChecked = true;
		}
		if (line.empty())
			continue ;
		std::stringstream ss(line);
		std::string name;
		std::getline(ss, name, ',');
		ss >> value;
		database[name] = value;
	}
	file.close();
}
bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(int year, int month, int day)
{
	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12 || day < 1)
		return (false);
	if (isLeapYear(year))
		daysInMonth[1] = 29; // Febbraio bisestile
	return (day <= daysInMonth[month - 1]);
}

float BitcoinExchange::getDateValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);

    if (it == database.begin() && it->first != date) {
        throw BadInput();
    }

    if (it == database.end() || it->first != date) {
        --it;
    }

    return it->second;
}

void BitcoinExchange::checkDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		throw BadInput();
	}


	int year, month, day;
	char dash1, dash2;
	std::istringstream dateStream(date);
	dateStream >> year >> dash1 >> month >> dash2 >> day;
	if (dateStream.fail() || dash1 != '-' || dash2 != '-')
	{
		throw BadInput();
	}
	if (!isValidDate(year, month, day))
	{
		throw BadInput();
	}
}

void BitcoinExchange::checkValue(float value)
{
	if (value < 0)
	{
		throw InvalidNumberNegative();
	}
	if (value > 1000)
	{
		throw InvalidNumberBig();
	}
}

void BitcoinExchange::exchangeBitcoin(std::string file)
{
	std::ifstream input_db(file.c_str(), std::ifstream::in);
	if (!input_db.is_open())
	{
		std::cerr << "Error: could not open input file\n";
		exit(1);
	}

	extractData();
	std::string line;
	std::string date;
	bool firstLineChecked = false;

	while (std::getline(input_db, line))
	{
		if (!firstLineChecked)
		{
			if (line == "date | value")
			{
				firstLineChecked = true;
				continue ;
			}
			else if (line.empty())
				continue ;
			else
				firstLineChecked = true;
		}

		if (line.empty())
			continue ;

		try
		{
			size_t sepPos = line.find('|');
			if (sepPos == std::string::npos)
				throw BadInput();
			date = line.substr(0, 10);
			checkDate(date);

			std::istringstream valueStream(line.substr(sepPos + 1));
			float value;
			valueStream >> value;
			if (valueStream.fail())
				throw BadInput();	
			checkValue(value);
			std::cout << date << " => " << value << " = " << getDateValue(date) * value << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what();
			if (std::string(e.what()) == "Error: bad input => ")
				std::cerr << date << std::endl;
			else
				std::cerr << std::endl;
		}
	}

	input_db.close();
}