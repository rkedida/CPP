/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/23 15:21:31 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <ostream>

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b)
{
	return b < a ? b : a;
}

template<typename T>
T const& max(T const& a, T const& b)
{
	return a < b ? b : a;
}

class Awesome
{
	private:
		int _n;

	public:
		Awesome(int n);
		~Awesome();
		int getType() const { return this->_n};
		bool operator==(Awesome const & rhs) const {return (this->_n == rhs._n); }
		bool operator!=(Awesome const & rhs) const {return (this->_n != rhs._n); }
		bool operator>(Awesome const & rhs) const {return (this->_n > rhs._n); }
		bool operator<(Awesome const & rhs) const {return (this->_n < rhs._n); }
		bool operator>=(Awesome const & rhs) const {return (this->_n >= rhs._n); }
		bool operator<=(Awesome const & rhs) const {return (this->_n <= rhs._n); }
		
};


#endif