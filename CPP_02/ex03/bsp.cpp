/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:36:28 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/02 11:49:52 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float triangleArea(const Point &a, const Point &b, const Point &c)
{
	float triangleArea = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
					+ b.getX().toFloat() * (a.getY().toFloat() - c.getY().toFloat())
					+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2;

	if (triangleArea < 0)
		triangleArea *= -1;
	return triangleArea;
}

static bool  check_vertex_or_edge(const Point &a, const Point &b, const Point &c, const Point &point)
{
	if ((a.getX().toFloat() == point.getX().toFloat() && (a.getY().toFloat() == point.getY().toFloat()))
		|| (b.getX().toFloat() == point.getX().toFloat() && b.getY().toFloat() == point.getY().toFloat())
		||( c.getX().toFloat() == point.getX().toFloat() && c.getY().toFloat() == point.getX().toFloat()))
	{
			std::cout << "It is in the vertex." << std::endl;
			return false;
	}
	return true;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float areaSum, area1,area2,area3;

	check_vertex_or_edge(a, b, c, point);
	areaSum = triangleArea(a, b, c);
	area1 = triangleArea(point, b, c);
	area2 = triangleArea(a, point, c);
	area3 = triangleArea(a, b, point);

	if (area1 == 0 || area2 == 0 || area3 == 0)
	{
		std::cout << "It is in the edge." << std::endl;
		return false;
	}
	return (areaSum == (area1 + area2 + area3));
}
