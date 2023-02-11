/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:01 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 19:34:45 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor Called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called." << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes: meow meow..." << std::endl;
}
