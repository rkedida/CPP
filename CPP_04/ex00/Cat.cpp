/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:01 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 16:35:45 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor Called." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& src)
{
	std::cout << "Cat Copy Constructor Called." << std::endl;
	this->type = src.type;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat Default Constructor Called." << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Copy Assignment Operator Called." << std::endl;
	this->type = src.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes: meow meow..." << std::endl;
}
