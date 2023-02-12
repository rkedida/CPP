/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:01 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 17:44:27 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor Called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& src)
{
	std::cout << "Cat Copy Constructor Called." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor Called." << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat Copy Assignment Operator Called." << std::endl;

	Brain* newbrain = new Brain();
	*newbrain = *(src.brain);
	delete brain;
	brain = newbrain;
	this->type = src.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes: meow meow..." << std::endl;
}
