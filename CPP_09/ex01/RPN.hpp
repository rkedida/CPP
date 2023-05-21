#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
	private:
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
	public:
		RPN();
		~RPN();

		double calculateRPN(const std::string &src);

};

#endif