/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 10:13:10 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::list<int> l2;
	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);

	try 
	{
		std::vector<int>::iterator it1 = easyfind(v, 3);
		std::cout << "Value found in vector at position: " << std::distance(v.begin(), it1) << std::endl;

		std::list<int>::iterator it2 = easyfind(l, 20);
		std::cout << "Value found in list at position: " << std::distance(l.begin(), it2) << std::endl;

		std::vector<int>::iterator it3 = easyfind(v, 10);
		std::cout << "Value found in vector at position: " << std::distance(v.begin(), it3) << std::endl;

		std::list<int>::iterator it4 = easyfind(l2, 10);
		std::cout << "Value found in vector at position: " << std::distance(l2.begin(), it4) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
