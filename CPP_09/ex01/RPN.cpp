/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/05/22 19:37:52 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

double RPN::calculateRPN(const std::string &expr)
{
	std::istringstream iss(expr);
	std::string token;
	std::stack<double> stack;
	
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: insufficient values in expression");
			double val2 = stack.top();
			stack.pop();
			double val1 = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(val1 + val2);
			else if (token == "-")
				stack.push(val1 - val2);
			else if (token == "*")
				stack.push(val1 * val2);
			else if (token == "/")
			{
				if (val2 == 0)
					throw std::runtime_error("Error: division by zero");
				stack.push(val1 / val2);
			}
		}
		else
		{
			std::istringstream iss2(token);
			double value;
			if (iss2 >> value)
				stack.push(value);
			else
				std::cerr << "Error: token couldn't converted." << std::endl;

		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: too many values in expression");

	return stack.top();
}
