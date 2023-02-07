/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:54 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/07 09:51:42 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	// ClapTrap ClapTrap("Robel");

	// for (int i = 0; i < 4; i++)
	// 	ClapTrap.attack("Balu");
	// ClapTrap.beRepaired(2);
	// for (int i = 0; i < 4; i++)
	// 	ClapTrap.attack("Balu");
	// ClapTrap.beRepaired(2);

	ScavTrap scavTrap("Robel");
	ScavTrap scavTrap2;

	scavTrap.attack("Balu");
	scavTrap.guardGate();
	scavTrap.beRepaired(2);

	scavTrap2.attack("Balu");
	scavTrap2.guardGate();
	scavTrap2.beRepaired(2);

	return 0;
}
