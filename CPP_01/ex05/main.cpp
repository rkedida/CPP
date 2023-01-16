/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:35:11 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/15 16:32:03 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl mssg;
	
	if (ac != 2)
	{
		std::cout << "Usage: ./Harl [Debug, Info, Warning, Error]" << std::endl;
		return (1);
	}
	for(int i = 0; i < ac; i++)
		mssg.complain(av[i]);
	return (0);
}