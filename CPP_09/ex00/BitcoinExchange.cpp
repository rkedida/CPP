/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/05/22 19:36:42 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _btcData(src._btcData)
{
}

BitcoinExchange::BitcoinExchange(const std::string& file)
{
	std::ifstream inFile(file.c_str());
	std::string line, date;
	double price;

	if (!inFile)
	{
		std::cerr << "Could not open File!" << std::endl;
		return ;
	}
	while (std::getline(inFile, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		ss >> price;
		_btcData[date] = price;
	}
	inFile.close();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		this->_btcData = src._btcData;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream inFile(filename.c_str());
	std::string line, date;
	double value;

	if (!inFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	while (std::getline(inFile, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, '|');
		ss >> value;

		if (ss.fail() || ss.peek() != EOF) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		std::map<std::string, double>::iterator it = _btcData.upper_bound(date);
		if (it == _btcData.begin() && it->first != date)
		{
			std::cerr << "Error: date not found." << std::endl;
		}
		else
		{
			if (it->first != date)
				--it;
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
	}
	inFile.close();
}
