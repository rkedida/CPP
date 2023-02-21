/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/21 11:58:13 by rkedida          ###   ########.fr       */
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
	// int i = 0;
	
	if (input.size() == 1 && isdigit(input[0]))
			return '\0';
	if (input.size() == 1 && !isdigit(input[0]))
		return input[0];
	if (myIsprintD(input[0]) && input[0] != '.')
	{
		// char c = input[0];
		return input[0];
	}
	if (input.length() == 0 || input.length() > 1)
		return '\0';
	return input[0];
}


int ScalarConverter::ConvertToInt(std::string& input)
{
	int d = myAtoi(input);


	if (d == -1)
		return -1;
	else
		return std::stoi(input);
}

// float ScalarConverter::ConvertToFloat(const std::string& input)
// {
// 	unsigned int i = 0;
// 	float f = 0.0f
// 	while (i < input.size() && input[i] == ' ')
// 		i++;
// 	if (input[i] == '+' || input[i] == '-')
// 		i++;
// 	for(; i < input.size(); i++)
// 	{
// 		if (isalpha(i) && input.back() != 'f')
// 			return -1;
// 		else
// 			f = strtof()
// 	}
// 	return 0;
// }

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
		{
			f = f * 10 + (c - '0');
			if (hasDot)
				f /= 10;
		}
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
        {
            d = d * 10 + (c - '0');
            if (hasDot)
                d /= 10;
        }
        else if (c == '.' && !hasDot)
            hasDot = true;
        else if (c == 'f' && i == input.size() - 1)
            return static_cast<float>(d);
        else
            return -1;
    }
    return d;
}

// double ScalarConverter::ConvertToDouble(const std::string& input)
// {

// 	 std::stod(input);
// 	std::cout << "impossible" << std::endl;
// 	return 0.0;
// 	if (input == "-inf" || input == "+inf")
// 		return input == "-inf" ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
// 	else if (input == "nan")
// 		return std::numeric_limits<double>::quiet_NaN();
// 	std::cout << "impossible" << std::endl;
// 	return 0.0;
// }

Type ScalarConverter::identifyType(std::string& input)
{
	if (input.length() == 1 && isalpha(input[0]) && myIsprint(input[0]) == 1)
		return CHAR;
	

	bool is_int = true;
	bool is_float = false;
	bool is_double = false;
	bool is_invalid = false;
	char c;

	for(int i = 0; i < static_cast<int>(input.size()); i++)
	{
		c = input[i];
		if (isalpha(c))
			return INVALID;
	}

	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		char c = input[i];
		if (c == '.' && !is_float && !is_double && !is_invalid)
		{
			if (input.back() == 'f')
			{
				is_int = false;
				is_float = true;
			}
			else if (input.back() != 'f' && isalpha(c))
			{
				is_int = false;
				is_float = false;
				is_invalid = true;
				return INVALID;
			}
			else
			{
				is_int = false;
				is_double = true;
			}
		}
	}

	if (is_int)
		return INT;
	else if (is_float)
		return FLOAT;
	else if (is_double)
		return DOUBLE;
	return INVALID;
}

std::string ScalarConverter::getType(std::string& input, ScalarConverter& converter)
{
	std::string startType;
	Type type = identifyType(input);
	converter.setType(type);
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
				return -1;

			result = result * 10 + (input[i] - '0');
			i++;
		}
		else
			return -1;
	}
	return sign * result;
}


void ScalarConverter::convert(std::string& input)
{
	ScalarConverter converter;
	std::string startType;

	converter.setChar('\0');	
	converter.setInt(0);	
	converter.setFloat(0.0f);	
	converter.setDouble(0.0);	
	startType = getType(input, converter);
	std::cout << startType << std::endl;


	char c = converter.ConvertToChar(input);
	converter.setChar(c);
	if (c == '\0')
		std::cout << "char: impossible\n";
	else
		std::cout << "char: '" << c << "'" << std::endl;

	// if (isdigit(input[0]))
	// 	std::cout << "int: impossible" << std::endl;
	int i = converter.ConvertToInt(input);
	if (i == -1 && input != "-1")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;


	if (input == "-inff" || input == "+inff" || input == "-inf" || input == "+inf" )
	{
		input == "-inff" ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
		std::cout << "float: " << input << std::endl;
	}
	else if (input == "nanf" || input == "nan")
	{
		std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << "nanf"	<< std::endl;
	}
	else
	{
		float f = converter.ConvertToFloat(input);
		if (isalpha(input[0]))
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
	}

	if (input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
	{
		input == "-inf" ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
		std::cout << "double: " << input << std::endl;
	}
	else if (input == "nanf" || input == "nan")
	{
		std::numeric_limits<float>::quiet_NaN();
		std::cout << "double: " << "nan" << std::endl;
	}
	else 
	{
		if (double d = converter.ConvertToDouble(input) == -1)
			std::cout << "double: impossible" << std::endl;
		else if (double d = converter.ConvertToDouble(input))
			std::cout << "double: " << d << ".0" << std::endl;
	}
}

// void ScalarConverter::convert(std::string& input)
// {
// 	ScalarConverter converter;

// 	char c = '\0';
// 	int i = 0;
// 	float f = 0.0f;
// 	double d = 0.0;
// 	std::string startType;

// 	startType = getType(input);
// 	std::cout << startType << std::endl;

// 	switch(identifyType(input))
// 	{
// 		case CHAR:
// 			c = ConvertToChar(input);
// 			std::cout << "char: " << c << std::endl;
// 			// break;
// 		case INT:
		
// 			if (myAtoi(input) != 0)
// 				i = ConvertToInt(input);
// 			// else
// 			// 	throw Impossible();
// 			if (i == 1)
// 				std::cout << "int: " << i << std::endl;
// 			else
// 				std::cout << "int: Non displayable" << std::endl;
// 			// break;
// 		case FLOAT:
// 			if (input == "+inff" || input == "-inff")
// 			{
// 				if (input == "+inff")
// 					std::cout << "float: +inff" << std::endl;
// 				else
// 					std::cout << "float: -inff" << std::endl;
// 			}
// 			else
// 			{
// 				f = ConvertToFloat(input);
// 				std::cout << "float: " << f << ".0f" << std::endl;
// 			}
// 			// break;
// 		case DOUBLE:
// 		if (input == "+inff" || input == "-inff")
// 			{
// 				if (input == "+inff")
// 					std::cout << "float: +inff" << std::endl;
// 				else
// 					std::cout << "float: -inff" << std::endl;
// 			}
// 			else
// 			{
// 				d = ConvertToDouble(input);
// 				std::cout << "double: " << d << ".0" << std::endl;
// 			}
// 			break;
// 		default:
// 			std::cout << "impossible";
// 			break;
// 	}
// }

int ScalarConverter::myIsprint(int ch)
{
	if (ch >= 32 && ch <= 127)
		return 1;
	return 0;
}

double ScalarConverter::myIsprintD(double ch)
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

void ScalarConverter::setChar(char c)
{
	this->c = c;
}

void ScalarConverter::setInt(int i)
{
	this->i = i;
}

void ScalarConverter::setFloat(float f)
{
	this->f = f;
}

void ScalarConverter::setDouble(double d)
{
	this->d = d;
}

void ScalarConverter::setType(Type& type)
{
	this->_type = type;
}

char ScalarConverter::getChar() const
{
	return this->c;
}

int ScalarConverter::getInt() const
{
	return this->i;
}

float ScalarConverter::getFloat() const
{
	return this->f;
}

double ScalarConverter::getDouble() const
{
	return this->d;
}

Type ScalarConverter::getTypo()
{
	return this->_type;
}

