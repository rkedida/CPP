/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/19 21:06:47 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor Called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << "ScalarConverter Copy Constructor Called." << std::endl;
	(void)src;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor Called." << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << "ScalarConverter Copy Assignment Operator Called." << std::endl;
	(void)src;

	return *this;
}

char ScalarConverter::ConvertToChar(const std::string& input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return input[0];
	std::cout << "char: ";
	if (input.length() == 0 || input.length() > 1)
	{
		std::cout << "impossible";
		return '\0';
	}
	if (!myIsprint(input[0]))
	{
		std::cout << "Non displayable" << std::endl;
		return '\0';
	}
	return input[0];
}


int ScalarConverter::ConvertToInt(const std::string& input)
{
	std::cout << "int: ";
	try
	{
		return std::stoi(input);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "impossible" << std::endl;
		return 0;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "impossible" << std::endl;
		return 0;
	}
}

float ScalarConverter::ConvertToFloat(const std::string& input)
{
	std::cout << "float: ";
	try
	{
		return std::stof(input);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "impossible" << std::endl;
		return 0.0f;
	}
	catch(const std::invalid_argument& e)
	{
		if (input == "-inff" || input == "+inff")
			return input == "-inff" ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
		else if (input == "nanf")
			return std::numeric_limits<float>::quiet_NaN();
	}
	std::cout << "impossible" << std::endl;
	return 0.0f;
	
}

double ScalarConverter::ConvertToDouble(const std::string& input)
{
	std::cout << "double: ";
	try
	{
		return std::stod(input);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "impossible" << std::endl;
		return 0.0;
	}
	catch(const std::invalid_argument& e)
	{
		if (input == "-inf" || input == "+inf")
			return input == "-inf" ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
		else if (input == "nan")
			return std::numeric_limits<double>::quiet_NaN();
	}
	std::cout << "impossible" << std::endl;
	return 0.0;
}

Type ScalarConverter::getType(std::string& input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return CHAR;

	bool is_int = true;
	bool is_float = true;

	for(int i = 0; i < static_cast<int>(input.size()); i++)
	{
		char c = input[i];
		if (c == '.' && is_float)
			is_int = false;
		else if (!isdigit(c))
		{
			is_int = false;
			is_float = false;
		}
	}

	if (is_int)
		return INT;
	else if (is_float)
		return FLOAT;
	else
		return DOUBLE;
}

void ScalarConverter::convert(std::string& input)
{
	ScalarConverter converter;

	switch(getType(input))
	{
		case CHAR:
			ConvertToChar(input);
			std::cout << std::endl;
			break;
		case INT:
			ConvertToInt(input);
			std::cout << std::endl;
			break;
		case FLOAT:
			ConvertToFloat(input);
			std::cout << std::endl;
			break;
		case DOUBLE:
			ConvertToDouble(input);
			std::cout << std::endl;
			break;
		default:
			std::cout << "impossible" << std::endl;
			break;
	}
}

int ScalarConverter::myIsprint(int ch)
{
	if (ch >= 32 && ch <= 127)
		return 1;
	return 0;
}