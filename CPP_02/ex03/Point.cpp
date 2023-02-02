/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:32:45 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/02 11:49:42 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f)
{
}

Point::Point(Point const &obj) : _x(obj.getX().getRawBits()), _y(obj.getY().getRawBits())
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point& Point::operator=(Point const &obj)
{
	(void)obj;
	return *this;
}

Point::~Point()
{
}

Fixed const& Point::getX() const
{
	return this->_x;
}

Fixed const& Point::getY() const
{
	return this->_y;
}
