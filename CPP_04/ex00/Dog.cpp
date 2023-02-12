/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:03 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 18:35:57 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constuctor Called." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& src)
{
	std::cout << "Dog Copy Consturctor Called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called." << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog Copy Assignment Operator Called." << std::endl;
	this->type = src.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes: wuff wuff..." << std::endl;
}
