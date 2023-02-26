/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 18:44:57 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main()
{
	// Test constructor and addNumber function
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	// Test shortestSpan and longestSpan functions
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

	// Test exception handling when adding too many numbers
	try {
		for (int i = 0; i < 5; i++) {
			sp1.addNumber(i);
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test exception handling when finding span with no or one element
	Span sp2 = Span(1);
	try {
		sp2.shortestSpan();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		sp2.longestSpan();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Generate 10000 random numbers
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10000);

	// Create a Span object and add the numbers
	Span sp3(10000);
	for (int i = 0; i < 10000; ++i) {
		sp3.addNumber(dis(gen));
	}

	// Calculate the shortest and longest span
	int shortest = sp3.shortestSpan();
	int longest = sp3.longestSpan();

	// Print the results
	std::cout << "Shortest span: " << shortest << std::endl;
	std::cout << "Longest span: " << longest << std::endl;

	return 0;
}
