/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:05:51 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/12 00:52:05 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout <<  this->_name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
