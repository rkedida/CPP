/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:26:03 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 12:16:20 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constuctor Called." << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "This Animal " << this->type << " makes: wuff wuff..." << std::endl;
}
