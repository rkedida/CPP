/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:59 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/07 14:45:47 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default Constructor Called." << std::endl;
	this->_name = "DiamondTrap";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap Parametic Constructor Called." << std::endl;
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : FragTrap(src), ScavTrap(src)
{
	std::cout << "DiamondTrap Copy Constructor Called." << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond Destructor Called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap Copy Assignment Constructor Called." << std::endl;
	this->_name = src._name + "_clap_trap";
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'am " << this->_name << " and my Base Class name is: " << ClapTrap::_name << "." << std::endl;
}
