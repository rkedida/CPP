/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:59 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/07 14:50:02 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor Called." << std::endl;
	this->_name = "ScavTrap";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parametic Constructor Called." << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	std::cout << "ScavTrap Copy Constructor Called." << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
	
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->takeDamage(this->_attack_damage);
		this->_energy_points -= 1;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no energy points left!" << std::endl;
}
