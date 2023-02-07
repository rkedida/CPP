/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:54 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/07 10:36:39 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	// ClapTrap ClapTrap("Robel");

	// for (int i = 0; i < 4; i++)
	// 	ClapTrap.attack("Balu");
	// ClapTrap.beRepaired(2);
	// for (int i = 0; i < 4; i++)
	// 	ClapTrap.attack("Balu");
	// ClapTrap.beRepaired(2);

	FragTrap scavTrap("Robel");
	FragTrap scavTrap2;

	scavTrap.attack("Balu");
	scavTrap.highFivesGuys();
	scavTrap.beRepaired(2);

	scavTrap2.attack("Balu");
	scavTrap2.highFivesGuys();
	scavTrap2.beRepaired(2);

	return 0;
}
