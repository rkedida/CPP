/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:35:11 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/15 17:17:36 by rkedida          ###   ########.fr       */
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
	mssg.complain(av[1]);
	return (0);
}
