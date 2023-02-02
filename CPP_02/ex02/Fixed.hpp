/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:21:55 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/22 17:19:28 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _fixed_point_value;
		static const int _fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();

		bool operator>(const Fixed &obj);
		bool operator<(const Fixed &obj);
		bool operator>=(const Fixed &obj);
		bool operator<=(const Fixed &obj);
		bool operator==(const Fixed &obj);
		bool operator!=(const Fixed &obj);

		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &fixedPoint1, Fixed &fixedPoint2);
		static const Fixed &min(const Fixed &fixedPoint1, const Fixed &fixedPoint2);
		static Fixed &max(Fixed &fixedPoint1, Fixed &fixedPoint2);
		static const Fixed &max(const Fixed &fixedPoint1, const Fixed &fixedPoint2);

		friend std::ostream &operator<<(std::ostream& COUT, const Fixed& obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

};

#endif