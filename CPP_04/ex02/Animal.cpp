/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:05 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 14:42:43 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Balu")
{
	std::cout << "Animal Default Constructor Called." << std::endl;
	
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal Copy Consturctor Called." << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called." << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << "Animal Copy Assignment Operator Called." << std::endl;
	this->type = src.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes a Sound." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
