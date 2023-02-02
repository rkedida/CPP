/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:36:28 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/02 09:21:27 by rkedida          ###   ########.fr       */
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

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float areaSum, area1,area2,area3;
	bool res1, res2;

	areaSum = triangleArea(a, b, c);
	area1 = triangleArea(point, b, c);
	area2 = triangleArea(a, point, c);
	area3 = triangleArea(a, b, point);

	res1 = (areaSum <= 0 || area1 <= 0 || area2 <= 0 || area3 <= 0);
	res2 = (areaSum != area1 + area2 +area3);

	if (res1 && res2)
		return false;
	return true;
}
