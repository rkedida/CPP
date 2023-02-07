/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:54 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/06 14:37:38 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap ClapTrap("Robel");

	for (int i = 0; i < 4; i++)
		ClapTrap.attack("Balu");
	ClapTrap.beRepaired(2);
	for (int i = 0; i < 4; i++)
		ClapTrap.attack("Balu");
	ClapTrap.beRepaired(2);

	return 0;
}
