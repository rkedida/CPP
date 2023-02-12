/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 16:45:21 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor Called." << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat& src)
{
	std::cout << "WrongCat Copy Constructor Called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << "WrongCat Copy Assignment Operator Called." << std::endl;
	this->type = src.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "This WrongCat " << this->type << " makes: meow meow ..." << std::endl;
}
