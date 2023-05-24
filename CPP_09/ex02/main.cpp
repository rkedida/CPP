/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/05/24 20:47:44 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe pmergeme;

	for (int i = 1; i < argc; ++i)
	{
		try
		{
			char* endptr;
			double num = std::strtod(argv[i], &endptr);
			if (*endptr != '\0' || endptr == argv[i])
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
	std::cout << "Before: ";
	pmergeme.printVector();

	clock_t start = clock();
	pmergeme.mergeInsertVector();
	clock_t stop = clock();
	clock_t duration = stop - start;

	std::cout << "After: ";
	pmergeme.printVector();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(7) << (double)duration / CLOCKS_PER_SEC << "s" << std::endl;

	std::cout << "Before: ";
	pmergeme.printList();

	start = clock();
	pmergeme.mergeInsertList();
	stop = clock();
	duration = stop - start;

	std::cout << "After: ";
	pmergeme.printList();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << std::fixed << std::setprecision(7) << (double)duration / CLOCKS_PER_SEC << "s" << std::endl;

	pmergeme.check_check();
	return 0;
}