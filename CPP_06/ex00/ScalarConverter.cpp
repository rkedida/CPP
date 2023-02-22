/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/22 23:34:05 by rkedida          ###   ########.fr       */
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
	if (input.length() == 0 || input.length() > 1)
		return '\0';
	if (input.length() == 1 && isdigit(input[0]))
			return input[0];
	if (input.length() == 1 && !isdigit(input[0]))
	{
		return input[0];
	}
	if (isprint(input[0]) && input[0] != '.')
		return input[0];
	return input[0];
}

int ScalarConverter::ConvertToInt(const std::string& input)
{
	int d = myAtoi(input);

	if (d == -1)
		return -1;
	else
		return std::stoi(input);
}

float ScalarConverter::ConvertToFloat(const std::string& input)
{
	unsigned int i = 0;
	float f = 0.0f;

	while (i < input.size() && input[i] == ' ')
		i++;
	
	if (input[i] == '+' || input[i] == '-')
		i++;

	bool hasDot = false;
	for(; i < input.size(); i++)
	{
		char c = input[i];
		if (isdigit(c))
			f = stof(input);
		else if (c == '.' && !hasDot)
			hasDot = true;
		else if (c == 'f' && i == input.size() - 1)
			return f;
		else
			return -1;
	}
	return f;
}

double ScalarConverter::ConvertToDouble(const std::string& input)
{
	unsigned int i = 0;
	double d = 0.0; 

	while (i < input.size() && input[i] == ' ')
		i++;

	if (input[i] == '+' || input[i] == '-')
		i++;

	bool hasDot = false;
	for(; i < input.size(); i++)
	{
		char c = input[i];
		if (isdigit(c))
			d = stod(input);
		else if (c == '.' && !hasDot)
			hasDot = true;
		else if (c == 'f' && i == input.size() - 1)
			return d;
		else
			return -1;
	}
	return d;
}

Type ScalarConverter::identifyType(const std::string& input)
{
	unsigned int i = 0;

	while (i < input.length())
	{
		if (input.length() == 1 && isalpha(input[0]) && isprint(input[0]) == 1 && !isdigit(input[0]))
			return CHAR;
		i++;
	}

	bool is_int = true;
	bool is_float = false;
	bool is_double = false;
	bool is_invalid = false;
	char c;

	for(int i = 0; i < static_cast<int>(input.size()); i++)
	{
		c = input[i];
		if (!isdigit(c) && c != '-' && c != '+' && c != '.' && c != 'f' && c != 'e')
			return INVALID;
	}

	if ((input.find('.') != std::string::npos) || input.find('f') != std::string::npos)
	{
		if (input.back() == 'f')
		{
			is_int = false;
			is_float = true;
			is_double = false;
		}
		else if (input.back() != 'f' || input.find('e'))
		{
			is_int = false;
			is_float = false;
			is_double = true;
		}
		else
		{
			is_int = false;
			is_float = false;
			is_invalid = true;
		}
	}
	if (is_int)
		return INT;
	else if (is_float)
		return FLOAT;
	else if (is_double)
		return DOUBLE;
	else if (is_invalid)
		return INVALID;
	return INVALID;
}

std::string ScalarConverter::getType(const std::string& input, ScalarConverter& converter)
{
	std::string startType;
	Type type = identifyType(input);
	converter._type = type;
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

int ScalarConverter::myAtoi(const std::string& input)
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
				return -1;

			result = result * 10 + (input[i] - '0');
			i++;
		}
		else
			return -1;
	}
	return sign * result;
}

void ScalarConverter::convert(const std::string& input)
{
	ScalarConverter converter;
	std::string startType;

	converter.c = '\0';
	converter.i = 0;
	converter.f = 0.0f;
	converter.d = 0.0;
	converter.overflow_i = false;
	converter.overflow_f = false;
	converter.overflow_d = false;

	char c = '\0';
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
	}
	else if ((input == "nan") || (input == "nanf"))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" <<  std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else
	{
		startType  = getType(input, converter);
		std::cout << startType << std::endl;
		switch (converter._type)
		{
			case CHAR:
				c = converter.ConvertToChar(input);
				converter.c = static_cast<char>(c);
				converter.i = static_cast<int>(c);
				converter.f = static_cast<float>(c);
				converter.d = static_cast<double>(c);
				
				std::cout << "char: " << converter.c << std::endl;
				std::cout << "int: " << converter.i << std::endl;
				std::cout << "float: " << converter.f << ".0f" <<  std::endl;
				std::cout << "double: " << converter.d << ".0" << std::endl;

				break;
			case INT:
				i = converter.ConvertToInt(input);
				converter.c = static_cast<char>(i);
				converter.i = static_cast<int>(i);
				converter.f = static_cast<float>(i);
				converter.d = static_cast<double>(i);

				if (converter.i == std::numeric_limits<int>::max() || converter.i == std::numeric_limits<int>::min())
					converter.overflow_i = true;
				if (converter.f == std::numeric_limits<float>::infinity() || converter.f == -std::numeric_limits<float>::infinity())
					converter.overflow_f = true;
				if (converter.d == std::numeric_limits<double>::infinity() || converter.d == -std::numeric_limits<double>::infinity())
					converter.overflow_d = true;

				if (converter.c == '\0' || !isprint(converter.c))
					std::cout << "char: " << "Non displayable" << std::endl;
				else if (!isdigit(converter.c) && isprint(converter.c))
					std::cout << "char: " << converter.c << std::endl;
				else
					std::cout << "char: imposssible" << std::endl;
				if ((converter.i == -1 && input != "-1") || converter.overflow_i == true)
					std::cout << "int: " << "impossible" << std::endl;
				else
					std::cout << "int: " << converter.i << std::endl;
				if ((converter.f == -1 && input != "-1") || converter.overflow_d == true)
					std::cout << "float: " << "impossible" << std::endl;
				else if (!(input.find('.') != std::string::npos))
					std::cout << "float: " << converter.f << ".0f" << std::endl;
				else
					std::cout << "float: " << converter.f << "f" << std::endl;
				if ((converter.d == -1 && input != "-1") || converter.overflow_d == true)
					std::cout << "double: " << "impossible" << std::endl;
				else if (!(input.find('.') != std::string::npos))
					std::cout << "double: " << converter.d << ".0" << std::endl;
				else
					std::cout << "double: " << converter.d << std::endl;

				break;
			case FLOAT:
				f = converter.ConvertToFloat(input);
				converter.c = static_cast<char>(f);
				converter.i = static_cast<int>(f);
				converter.f = static_cast<float>(f);
				converter.d = static_cast<double>(f);
				if (converter.i == std::numeric_limits<int>::max() || converter.i == std::numeric_limits<int>::min())
					converter.overflow_i = true;
				if (converter.f == std::numeric_limits<float>::infinity() || converter.f == -std::numeric_limits<float>::infinity())
					converter.overflow_f = true;
				if (converter.d == std::numeric_limits<double>::infinity() || converter.d == -std::numeric_limits<double>::infinity())
					converter.overflow_d = true;
				
				if (isprint(converter.c))
					std::cout << "char: " << converter.c << std::endl;
				else
					std::cout << "char: " << "impossible" << std::endl;
				if ((converter.i == -1 && input != "-1") || converter.overflow_i == true)
					std::cout << "int: " << "impossible" << std::endl;
				else
					std::cout << "int: " << converter.i << std::endl;
				if ((converter.f == -1 && input != "-1") || converter.overflow_d == true)
					std::cout << "float: " << "impossible" << std::endl;
				else if (input.find('.') != std::string::npos && std::fmod(converter.f, 1.0) == 0.0)
					std::cout << "float: " << converter.f << ".0f" << std::endl;
				else
					std::cout << "float: " << converter.f << "f" << std::endl;
				if ((converter.d == -1 && input != "-1") || converter.overflow_d == true)
					std::cout << "double: " << "impossible" << std::endl;
				else if (input.find('.') != std::string::npos && std::fmod(converter.f, 1.0) == 0.0)
					std::cout << "double: " << converter.d << ".0" << std::endl;
				else
					std::cout << "double: " << converter.d << std::endl;

				break;
			case DOUBLE:
				d = converter.ConvertToDouble(input);
				converter.c = static_cast<char>(d);
				converter.i = static_cast<int>(d);
				converter.f = static_cast<float>(d);
				converter.d = static_cast<double>(d);

				if (converter.i == std::numeric_limits<int>::max() || converter.i == std::numeric_limits<int>::min())
					converter.overflow_i = true;
				if (converter.f == std::numeric_limits<float>::infinity() || converter.f == -std::numeric_limits<float>::infinity())
					converter.overflow_f = true;
				if (converter.d == std::numeric_limits<double>::infinity() || converter.d == -std::numeric_limits<double>::infinity())
					converter.overflow_d = true;

				if (isprint(converter.c))
					std::cout << "char: " << converter.c << std::endl;
				else
					std::cout << "char: " << "impossible" << std::endl;
				if ((converter.i == -1 && input != "-1") || converter.overflow_i == true)
					std::cout << "int: " << "impossible" << std::endl;
				else
					std::cout << "int: " << converter.i << std::endl;
				if ((converter.f == -1 && input != "-1") || converter.overflow_d == true)
					std::cout << "float: " << "impossible" << std::endl;
				else if (input.find('.') != std::string::npos && std::fmod(converter.f, 1.0) == 0.0)
					std::cout << "float: " << converter.f << ".0f" << std::endl;
				else
					std::cout << "float: " << converter.f << "f" << std::endl;
				if ((converter.d == -1 && input != "-1") || converter.overflow_d == true)
					std::cout << "double: " << "impossible" << std::endl;
				else if (input.find('.') != std::string::npos && std::fmod(converter.f, 1.0) == 0.0)
					std::cout << "double: " << converter.d << ".0" << std::endl;
				else
					std::cout << "double: " << converter.d << std::endl;

				break;
			case INVALID:
				std::cout << "char: " << "impossible" << std::endl;
				std::cout << "int: " << "impossible" << std::endl;
				std::cout << "float: " << "impossible" << std::endl;
				std::cout << "double: " << "impossible" << std::endl;

				break;
		}
	}
}

double ScalarConverter::myIsprintD(double ch)
{
	if (ch >= 32 && ch <= 127)
		return 1;
	return 0;
}
