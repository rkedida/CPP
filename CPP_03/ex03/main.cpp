/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:54 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/07 13:51:11 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	// ClapTrap ClapTrap("Robel");

	// for (int i = 0; i < 4; i++)
	// 	ClapTrap.attack("Balu");
	// ClapTrap.beRepaired(2);
	// for (int i = 0; i < 4; i++)
	// 	ClapTrap.attack("Balu");
	// ClapTrap.beRepaired(2);

	DiamondTrap scavTrap("Robel");
	DiamondTrap scavTrap2;

	scavTrap.whoAmI();

	scavTrap.attack("Balu");
	scavTrap.highFivesGuys();
	scavTrap.beRepaired(2);

	scavTrap2.attack("Balu");
	scavTrap2.highFivesGuys();
	scavTrap2.beRepaired(2);

	scavTrap2.whoAmI();

	return 0;
}
