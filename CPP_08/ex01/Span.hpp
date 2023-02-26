/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 17:51:28 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <random>
# include <exception>

class Span
{
	private:
		unsigned int _N;
		std::vector<unsigned int> vec;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& src);
		~Span();

		Span& operator=(const Span& src);

		void addNumber(unsigned int N);
		int shortestSpan() const;
		int longestSpan() const;
};

// std::ostream& operator<<(const std::ostream& out, const Span& src);

#endif