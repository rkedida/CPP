/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/24 14:58:01 by rkedida          ###   ########.fr       */
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

class Whatever
{
	private:
		float _i;

	public:
		Whatever(float i) : _i(i) {};
		
		float getType() const { return this->_i;}
		bool operator==(Whatever const & rhs) const;
		bool operator!=(Whatever const & rhs) const;
		bool operator>(Whatever const & rhs) const;
		bool operator<(Whatever const & rhs) const;
		bool operator>=(Whatever const & rhs) const;
		bool operator<=(Whatever const & rhs) const;

};

std::ostream& operator<<(std::ostream& out, const Whatever& src);

#endif