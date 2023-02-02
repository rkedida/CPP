/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:29:54 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/29 16:41:37 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_value(0)
{
}

Fixed::Fixed(const int n) : _fixed_point_value(static_cast<int>(n << _fractional_bits))
{
}

Fixed::Fixed(const float n) : _fixed_point_value(roundf(static_cast<float>(n * (1 << _fractional_bits))))
{
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	this->_fixed_point_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

bool Fixed::operator>(Fixed const &obj)
{
	if (this->getRawBits() > obj.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<(Fixed const &obj)
{
	if (this->getRawBits() < obj.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>=(Fixed const &obj)
{
	if (this->getRawBits() >= obj.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<=(Fixed const &obj)
{
	if (this->getRawBits() <= obj.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator==(Fixed const &obj)
{
	if (this->getRawBits() == obj.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!=(Fixed const &obj)
{
	if (this->getRawBits() != obj.getRawBits())
		return true;
	else
		return false;
}

Fixed Fixed::operator+(Fixed const &obj) const
{
	Fixed cpy;

	cpy.setRawBits(this->getRawBits() + obj.getRawBits());

	return cpy;
}

Fixed Fixed::operator-(Fixed const &obj) const
{
	Fixed cpy;

	cpy.setRawBits(this->getRawBits() - obj.getRawBits());

	return cpy;
}

Fixed Fixed::operator*(Fixed const &obj) const
{
	Fixed cpy;

	cpy.setRawBits((this->getRawBits() * obj.getRawBits()) /( 1 << _fractional_bits));

	return cpy;
}

Fixed Fixed::operator/(Fixed const &obj) const
{
	Fixed cpy;

	cpy.setRawBits(this->getRawBits() / obj.getRawBits());

	return cpy;
}

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed cpy(*this);

	this->setRawBits(this->getRawBits() + 1);
	return cpy;
}

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);

	this->setRawBits(this->getRawBits() - 1);
	return cpy;
}

Fixed &Fixed::min(Fixed &fixedPoint1, Fixed &fixedPoint2)
{
	if (fixedPoint1 < fixedPoint2)
		return fixedPoint1;
	return fixedPoint2;
}

Fixed const &Fixed::min(Fixed const &fixedPoint1, Fixed const &fixedPoint2)
{
	if (static_cast<Fixed>(fixedPoint1) < static_cast<Fixed>(fixedPoint2))
		return fixedPoint1;
	return fixedPoint2;
}

Fixed &Fixed::max(Fixed &fixedPoint1, Fixed &fixedPoint2)
{
	if (fixedPoint1 > fixedPoint2)
		return fixedPoint1;
	return fixedPoint2;
}

Fixed const &Fixed::max(Fixed const &fixedPoint1, Fixed const &fixedPoint2)
{
	if (static_cast<Fixed>(fixedPoint1) > static_cast<Fixed>(fixedPoint2))
		return fixedPoint1;
	return fixedPoint2;
}

std::ostream &operator<<(std::ostream& COUT, const Fixed& obj)
{
	COUT << obj.toFloat();
	return COUT;
}

int Fixed::getRawBits(void) const
{
	return this->_fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixed_point_value) / static_cast<float>(1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
	return static_cast<int>(this->_fixed_point_value >> _fractional_bits);
}
