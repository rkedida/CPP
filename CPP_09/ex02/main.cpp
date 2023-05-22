#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe pmergeme;

	// Read argv and save numbers in list and vector
	for (int i = 1; i < argc; ++i)
	{
		try
		{
			char* endptr;
			double num = std::strtod(argv[i], &endptr);
			if (*endptr != '\0' || endptr == argv[i]) // If conversion failed
				throw std::invalid_argument("Invalid argument");
			if (num < 0)
				throw std::invalid_argument("Negative number encountered");
			pmergeme.addNumber(num);
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
			return 1;
		}
	}

	// Print unsorted sequence
	std::cout << "Before: ";
	pmergeme.printVector();

	// Sort the vector and print time taken
	clock_t start = clock();
	pmergeme.mergeInsertVector();
	clock_t stop = clock();
	clock_t duration = stop - start;

	// Print sorted sequence
	std::cout << "After: ";
	pmergeme.printVector();
	std::cout << "Time to process a range of "<< argc -1 << " elements with std::vector : " <<std::fixed << std::setprecision(7) << (double)duration / CLOCKS_PER_SEC << "s" << std::endl;

	// Reset vector and list to unsorted state
	pmergeme.resetVectorList();
	// Print unsorted sequence
	std::cout << "Before: ";
	pmergeme.printList();

	// Sort the list and print time taken
	start = clock();
	pmergeme.mergeInsertList();
	stop = clock();
	duration = stop - start;

	// Print sorted sequence
	std::cout << "After: ";
	pmergeme.printList();
	std::cout << "Time to process a range of "<< argc -1 << " elements with std::list : " <<std::fixed << std::setprecision(7) << (double)duration / CLOCKS_PER_SEC << "s" << std::endl;
	return 0;
}