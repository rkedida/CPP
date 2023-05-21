#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _btcData;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange(const std::string& file);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void processInput(const std::string& src);
};

#endif