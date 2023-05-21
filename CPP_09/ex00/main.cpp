#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	BitcoinExchange btc("data.csv");
	btc.processInput(av[1]);

	return 0;
}