/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/19 21:04:31 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cmath>
# include <sstream>

enum Type {INVALID, CHAR, INT, FLOAT, DOUBLE};

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

		ScalarConverter& operator=(const ScalarConverter& src);

		static char ConvertToChar(const std::string& input);
		static int ConvertToInt(const std::string& input);
		static float ConvertToFloat(const std::string& input);
		static double ConvertToDouble(const std::string& input);

		
		static Type getType(std::string& input);
		static void convert(std::string& input);

		static int myIsprint(int ch);
};

#endif