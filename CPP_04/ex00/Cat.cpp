/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:01 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 12:16:30 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor Called." << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Default Constructor Called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes: meow meow..." << std::endl;
}
