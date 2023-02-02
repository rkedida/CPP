/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:31:37 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/02 09:26:58 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(Point const &obj);
		Point(float const x, float const y);
		Point& operator=(Point const &obj);
		~Point();

		Fixed const& getX() const;
		Fixed const& getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif