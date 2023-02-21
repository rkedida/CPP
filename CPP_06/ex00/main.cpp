/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/21 00:05:08 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

// int main(int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		std::cout << "usage: " << av[0] << " [literal]" << std::endl;
// 		return 1;
// 	}
	
// 	std::string input = av[1];
// 	if (input.size() == 1 && !isdigit(input[0]))
// 	{
// 		std::cout << "char: " << input[0] << std::endl;
// 		ScalarConverter::ConvertToInt(input);
// 		ScalarConverter::ConvertToFloat(input);
// 		ScalarConverter::ConvertToDouble(input);
// 	}
// 	else
// 	{
// 		if (input == "nanf" || input == "+inff" || input == "-inff")
// 		{
// 			std::cout << "char: impossible" << std::endl;
// 			std::cout << "int: impossible" << std::endl;
// 		}
// 		else
// 		{
// 			ScalarConverter::ConvertToChar(input);
// 			ScalarConverter::ConvertToInt(input);
// 		}
// 		ScalarConverter::ConvertToFloat(input);
// 		ScalarConverter::ConvertToDouble(input);
// 	}
// }

int main(int ac, char **av)
{
	std::string input;

	if (ac != 2)
	{
		std::cout << "usage: " << av[0] << " [literal]" << std::endl;
		return 1;
	}
	input = av[1];
	// if (input.size() > 1)
	// {
	// 	for(int i = 0; i  < input.size(); i++)
	// 	{
	// 		if (isalpha(input[i]))
	// 			return 0;
	// 	}
	// }
	ScalarConverter::convert(input);
	return 0;
}