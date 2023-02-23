/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/22 21:39:54 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialize.hpp"

Data::Data()
{
	std::cout << "Data Default Constructor Called." << std::endl;
}

Data::Data(const Data& src)
{
	std::cout << "Data Copy Constructor Called." << std::cout;
	(void)src;
}

Data::~Data()
{
	std::cout << "Data Destructor Called." << std::endl;
}

Data& Data::operator=(const Data& src)
{
	std::cout << "Data Copy Assignment Operator Called." << std::endl;
	(void)src;

	return *this;
}
