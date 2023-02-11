/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 13:38:14 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor Called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "This WrongCat makes: meow meow ..." << std::endl;
}
