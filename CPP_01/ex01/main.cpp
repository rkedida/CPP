/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:40:51 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 01:37:42 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Zombie;
	
	Zombie = zombieHorde(5, "Robel");

	for(int i = 0; i < 5; i++)
		Zombie[i].announce();
	delete [] Zombie;

	return (0);
}
