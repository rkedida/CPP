/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:05 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 12:16:08 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Balu")
{
	std::cout << "Animal Default Constructor Called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes a Sound." << std::endl;
}
