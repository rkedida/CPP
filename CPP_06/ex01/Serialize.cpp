/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/23 10:42:06 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialize.hpp"

Serialize::Serialize()
{
	std::cout << "Serialize Default Constructor Called." << std::endl;
}

Serialize::Serialize(const Serialize& src)
{
	std::cout << "Serialize Copy Constructor Called." << std::endl;
	(void)src;
}

Serialize::~Serialize()
{
	std::cout << "Serialize Destructor Called." << std::endl;
}

Serialize& Serialize::operator=(const Serialize& src)
{
	std::cout << "Serialize Copy Assignment Operator Called." << std::endl;
	(void)src;

	return (*this);
}

uintptr_t Serialize::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
