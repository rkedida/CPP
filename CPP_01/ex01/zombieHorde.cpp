/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:41:49 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 01:32:40 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{
	Zombie *newZombie = new Zombie[N];

	for(int i = 0; i < N; i++)
		newZombie[i].set_name(name);

	return (newZombie);
}
