/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/24 16:26:21 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"

bool Whatever::operator==(Whatever const & rhs) const
{
	return (this->_i == rhs._i);
}
bool Whatever::operator!=(Whatever const & rhs) const
{
	return (this->_i != rhs._i);
}
bool Whatever::operator>(Whatever const & rhs) const
{
	return (this->_i > rhs._i); 
}
bool Whatever::operator<(Whatever const & rhs) const
{
	return (this->_i < rhs._i); 
}
bool Whatever::operator>=(Whatever const & rhs) const
{
	return (this->_i >= rhs._i);
}
bool Whatever::operator<=(Whatever const & rhs) const
{
	return (this->_i <= rhs._i);
}

std::ostream& operator<<(std::ostream& out, const Whatever& src)
{
	out << src.getType();
	return out;
};

int main()
{
	Whatever a (2.7);
	Whatever b (3.9);
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;	
	std::cout << "Comparing a and b: " << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;

	std::cout << std::endl;
	std::cout << "Comparing c and d: " << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;

	return 0;
}
