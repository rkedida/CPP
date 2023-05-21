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
			stack.push(std::stod(token));
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: too many values in expression");

	return stack.top();
}
