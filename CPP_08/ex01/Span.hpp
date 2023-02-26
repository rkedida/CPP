/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 10:53:29 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
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
		void addNumbers(unsigned int N);
		int shortestSpan() const;
		int longestSpan() const;
};

#endif