/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 10:59:48 by rkedida          ###   ########.fr       */
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
}

Span::Span(const Span& src)
{
	std::cout << "Span Copy Constructor Called." << std::endl;
}

Span::~Span()
{
	std::cout << "Span Destructor Called." << std::endl;
}

Span& Span::operator=(const Span& src)
{
	std::cout << "Span Copy Assignment Operator Called." << std::endl;
}

void Span::addNumbers(unsigned int N)
{
	if (vec.size() == this->_N)
		throw std::out_of_range("Maximum number reached.");
	vec.push_back(N);
}




