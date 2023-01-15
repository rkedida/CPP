/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:19:54 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/15 10:21:44 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string& name, Weapon& weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
	_weapon = &weapon;
}
