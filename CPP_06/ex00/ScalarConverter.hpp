/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/21 22:58:41 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <string>
# include <limits>
# include <cctype>
# include <cmath>
# include <sstream>

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
		Type _type;

		enum Type type;
		ScalarConverter& operator=(const ScalarConverter& src);

		static char ConvertToChar(std::string& input);
		static int ConvertToInt( std::string& input);
		static float ConvertToFloat(const std::string& input);
		static double ConvertToDouble(const std::string& input);

		
		static Type identifyType(std::string& input);
		static std::string getType(std::string& input, ScalarConverter& converter);
		static int myAtoi(std::string& input);
		static void convert(std::string& input);

		static int myIsprint(int ch);
		static double myIsprintD(double ch);

		class Impossible : public std::exception
		{
			const char* what() const throw();
		};

		class NonDisplayable : public std::exception
		{
			const char* what() const throw();
		};

		void setChar(char c);
		void setInt(int i);
		void setFloat(float f);
		void setDouble(double d);
		void setType(Type& type);

		char getChar() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
		Type getTypo();
};

#endif