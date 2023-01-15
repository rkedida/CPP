/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:46:56 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 02:00:47 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;
	
	std::cout << "The memory address of the str is:     " << &str << std::endl;
	std::cout << "The memory address of the strPTR is:  " << strPTR << std::endl;
	std::cout << "The memory address of the strREF is:  " << &strREF << std::endl;

	std::cout << "The value of the str is:              " << str << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *strPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << strREF << std::endl;
	
	return(0);
}