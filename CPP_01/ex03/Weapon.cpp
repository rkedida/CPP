/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:52:23 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 08:53:34 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string& type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string& type)
{
	this->_type = type;
}

const std::string &Weapon::getType()
{
	return (this->_type);
}
