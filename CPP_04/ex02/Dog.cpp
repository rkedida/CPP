/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:03 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 17:44:20 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constuctor Called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& src)
{
	std::cout << "Dog Copy Constructor Called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor Called." << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog Copy Assignment Operator Called." << std::endl;
	
	Brain* newbrain = new Brain();
	*newbrain = *(src.brain);
	delete brain;
	brain = newbrain;
	this->type = src.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes: wuff wuff..." << std::endl;
}
