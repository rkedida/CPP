/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/20 17:14:18 by rkedida          ###   ########.fr       */
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
	if (input.size() == 1 && !isdigit(input[0]))
		return input[0];
	if (!myIsprint(input[0]))
		throw NonDisplayable();
	if (input.length() == 0 || input.length() > 1)
		throw Impossible();
	return input[0];
}


int ScalarConverter::ConvertToInt(const std::string& input)
{
	try
	{
		std::stoi(input);
		return 1;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}
}

float ScalarConverter::ConvertToFloat(const std::string& input)
{
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
	try
	{
		return std::stod(input);
	}
	catch(const std::exception& e)
	{
		throw Impossible();
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

Type ScalarConverter::identifyType(std::string& input)
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

std::string ScalarConverter::getType(std::string& input)
{
	Type type;
	std::string startType;

	type = identifyType(input);
	for (int idx = 0; idx <= 4; idx++)
	{
		if (type == 0)
			startType = "The identified Type is: INVALID";
		else if (type == 1)
			startType = "The identified Type is: CHAR";
		else if (type == 2)
			startType = "The identified Type is: INT";
		else if (type == 3)
			startType = "The identified Type is: FLOAT";
		else if (type == 4)
			startType = "The identified Type is: DOUBLE";
	}
	return startType;
}

int ScalarConverter::myAtoi(std::string& input)
{
	int result = 0;
	int sign = 1;
	unsigned long i = 0;

	while (i < input.length() && input[i] == ' ')
		i++;

	if (i < input.length() && (input[i] == '+' || input[i] == '-'))
	{
		sign = (input[i] == '-') ? -1 : 1;
		i++;
	}

	while (i < input.length())
	{
		if(input[i] >= '0' && input[i] <= '9')
		{
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (input[i] - '0') > INT_MAX % 10))
				return (sign == -1) ? INT_MIN : INT_MAX;

			result = result * 10 + (input[i] - '0');
			i++;
		}
		else
			break;
	}
	return sign * result;
}

void ScalarConverter::convert(std::string& input)
{
	ScalarConverter converter;

	char c;
	int i;
	float f;
	double d;
	std::string startType;

	startType = getType(input);
	std::cout << startType << std::endl;

	switch(identifyType(input))
	{
		case CHAR:
			c = ConvertToChar(input);
			std::cout << "char: " << c << std::endl;
			// break;
		case INT:
		
			if (myAtoi(input))
				i = ConvertToInt(input);
			else
				throw Impossible();
			if (i == 1)
				std::cout << "int: " << i << std::endl;
			else
				std::cout << "int: Non displayable" << std::endl;
			// break;
		case FLOAT:
			if (input == "+inff" || input == "-inff")
			{
				if (input == "+inff")
					std::cout << "float: +inff" << std::endl;
				else
					std::cout << "float: -inff" << std::endl;
			}
			else
			{
				f = ConvertToFloat(input);
				std::cout << "float: " << f << ".0f" << std::endl;
			}
			// break;
		case DOUBLE:
		if (input == "+inff" || input == "-inff")
			{
				if (input == "+inff")
					std::cout << "float: +inff" << std::endl;
				else
					std::cout << "float: -inff" << std::endl;
			}
			else
			{
				d = ConvertToDouble(input);
				std::cout << "double: " << d << ".0" << std::endl;
			}
			break;
		default:
			std::cout << "impossible";
			break;
	}
}

int ScalarConverter::myIsprint(int ch)
{
	if (ch >= 32 && ch <= 127)
		return 1;
	return 0;
}

const char* ScalarConverter::Impossible::what() const throw()
{
	return "impossible";
}

const char* ScalarConverter::NonDisplayable::what() const throw()
{
	return "Non displayable";
}
