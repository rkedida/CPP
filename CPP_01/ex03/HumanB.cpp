/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:36:45 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 08:27:16 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}