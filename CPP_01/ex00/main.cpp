/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:03:18 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/12 00:51:23 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Foo = newZombie("Foo:");

	Foo->announce();
	delete Foo;
	randomChump("Balu:");
	return (0);
}
