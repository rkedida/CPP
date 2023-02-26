/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 20:52:14 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <algorithm>
# include <list>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& src) : std::stack<T>(src) {}
		~MutantStack() {}

		MutantStack& operator=(const MutantStack& src)
		{
			this->c = src.c;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};

#endif