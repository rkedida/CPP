/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/22 18:48:43 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>

enum Type {INVALID, CHAR, INT, FLOAT, DOUBLE};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

	public:
		char c;
		int	i;
		float f;
		double d;
		bool overflow_i;
		bool overflow_f;
		bool overflow_d;
		Type _type;

		enum Type type;
		ScalarConverter& operator=(const ScalarConverter& src);

		static char ConvertToChar(const std::string& input);
		static int ConvertToInt(const std::string& input);
		static float ConvertToFloat(const std::string& input);
		static double ConvertToDouble(const std::string& input);

		
		static Type identifyType(const std::string& input);
		static std::string getType(const std::string& input, ScalarConverter& converter);
		static int myAtoi(const std::string& input);
		static void convert(const std::string& input);

		static double myIsprintD(double ch);
};

#endif