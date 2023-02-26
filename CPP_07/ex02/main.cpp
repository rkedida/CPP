/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 09:15:07 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int main()
{

		Array<unsigned int>* a = new Array<unsigned int>(22);
		unsigned int*  a1 = new unsigned int();

		try
		{
			Array<unsigned int>c = Array<unsigned int>(3);		
			c[1] = 1;
			std::cout << c[1] << std::endl;
			std::cout << c[6] << std::endl;
			std::cout << c << std::endl;
			std::cout << c.size() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		
		
		std::cout << std::endl;
		std::cout << a << std::endl;
		std::cout << &a << std::endl;
		std::cout << *a<< std::endl;
		std::cout << std::endl;
		std::cout << a->size() << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << a1 << std::endl;
		std::cout << &a1 << std::endl;
		std::cout << *a1 << std::endl;
		std::cout << std::endl;

		delete a;
		delete a1;


	return 0;
}
