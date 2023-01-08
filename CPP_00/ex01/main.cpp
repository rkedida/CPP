/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:39 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/08 01:41:51 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	command;
	
	while(command.compare("EXIT") != 0 && !std::cin.eof())
	{
		std::cout << "Your PhoneBook has " << phonebook.get_total() << " contact.\n";
		std::cout << "You can use the following commands: ADD, SEARCH, EXIT.\n";
		std::cout << "Enter a command: ";
		getline(std::cin, command);
		if (command.compare("ADD") == 0)
		{	std::cout << std::endl;
			phonebook.create_contact();
		}
		else if (command.compare("SEARCH") == 0)
			phonebook.search_contact();
	}
	return (0);
}
