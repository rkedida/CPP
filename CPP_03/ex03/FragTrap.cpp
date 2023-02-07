/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:54 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/07 14:45:08 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor Called." << std::endl;
	this->_name = "FragTrap";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Parametic Constructor Called." << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src)
{
	std::cout << "FragTrap Copy Constructor Called." << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap Copy Assignment Operator Called." << std::endl;
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
		if (this->_energy_points > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->takeDamage(this->_attack_damage);
		this->_energy_points -= 1;
	}
	else
		std::cout << "FragTrap " << this->_name << " has no energy points left!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " asks for a high five." << std::endl;
}
