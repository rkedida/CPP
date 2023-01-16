/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:35:22 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/15 17:26:17 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*arr[5]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"Debug", "Info", "Warning", "Error"};
	int i = 0;

	for(; i < 4; i++)
			if (!levels[i].compare(level))
			break;
	switch(i)
	{
		case 0:
			std::cout << "[ Debug ]" << std::endl;
			(this->*arr[0])();
		case 1:
			std::cout << "[ Info ]" << std::endl;
			(this->*arr[1])();
		case 2:
			std::cout << "[ Warning ]" << std::endl;
			(this->*arr[2])();
		case 3:
			std::cout << "[ Error ]" << std::endl;
			(this->*arr[3])();
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		
	}
	return;
}
