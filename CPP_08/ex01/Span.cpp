/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 18:31:50 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span() : _N(0), vec(0)
{
	std::cout << "Span Default Constructor Called." << std::endl;
}

Span::Span(unsigned int N)
{
	std::cout << "Span Parametic Constructor Called." << std::endl;
	if (N <= 0)
		throw std::out_of_range("Needs to be unsigned.");
	else
		this->_N = N;
}

Span::Span(const Span& src)
{
	std::cout << "Span Copy Constructor Called." << std::endl;
	*this = src;
}

Span::~Span()
{
	std::cout << "Span Destructor Called." << std::endl;
}

Span& Span::operator=(const Span& src)
{
	std::cout << "Span Copy Assignment Operator Called." << std::endl;

	this->_N = src._N;
	this->vec = src.vec;

	return *this;
}

void Span::addNumber(unsigned int N)
{
	if (vec.size() == this->_N)
		throw std::out_of_range("Maximum number reached.");
	vec.push_back(N);
}

int Span::shortestSpan() const
{
	if (vec.size() < 2)
		throw std::out_of_range("Not eough numbers to calculate Span.");
	std::vector<unsigned int> sortedNumbers = vec;
	unsigned int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (unsigned int i = 2; i < sortedNumbers.size(); i++)
	{
		unsigned int span = sortedNumbers[i] - sortedNumbers[i-1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (vec.size() < 2)
		throw std::out_of_range("Not eough numbers to calculate Span.");
	unsigned int min; 
	min = *std::min_element(vec.begin(), vec.end());
	unsigned int max;
	max = *std::max_element(vec.begin(), vec.end());

	return max - min;
}

// std::ostream& Span::operator<<(const std::ostream& out, const Span& src)
// {
// }
