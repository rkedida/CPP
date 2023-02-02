/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:36:53 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/02 09:28:50 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point A(0.0f,0.0f);
	Point B(-2.0f, 0.0f);
	Point C(0.0f, 2.0f);

	Point P(0.0f, 2.0f);
	
	if (bsp(A, B, C, P))
		std::cout << "Point P lies in the triangle ABC" << std::endl;
	else
		std::cout << "Point P does not lie in the triangle ABC" << std::endl;
	return 0;
}
