#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: incorrect number of arguments" << std::endl;
		return 1;
	}
	try
	{
		RPN a;
		double result = a.calculateRPN(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}