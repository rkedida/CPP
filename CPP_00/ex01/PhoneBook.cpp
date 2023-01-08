/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:03:04 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/08 16:35:09 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->total = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::set_total(int total)
{
	this->total = total++;
}

int PhoneBook::get_total(void)
{
	return (this->total);
}

static void error(std::string error)
{
	std::cout << error << " cannot be empty" << std::endl;
	std::cout << std::endl;
}

static int check_string(std::string s1, std::string s2)
{
	if (s2.empty())
	{
		error(s1);
		return (-1);
	}
	else if (s2.empty())
	{
		error(s1);
		return (-1);
	}
	return (0);
}

void PhoneBook::create_contact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	std::string buffer;

	std::cout << "First name: ";
	std::getline(std::cin, first_name);
	if (check_string("First name", first_name) == -1)
		return;
	std::cout << "Last name: ";
	std::getline(std::cin, last_name);
	if (check_string("Last name", last_name) == -1)
		return;
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (check_string("Nickname", nickname) == -1)
		return;
	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);
	if (check_string("Phone number", phone_number) == -1)
		return;
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (check_string("Darkest secret", darkest_secret) == -1)
		return;
	std::cout << std::endl;
	
	this->contacts[this->index].init_contact(first_name, last_name,
							nickname, phone_number, darkest_secret);
	
	if (this->total < 8)
		this->total++;
	this->index = (this->index + 1) % 8;
}

int PhoneBook::string_to_int(std::string buffer)
{
	int i = 0;
	int result = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
			result = result * 10 + (buffer[i] - '0');
		else
			return (-1);
		i++;
	}
	return (result);
}

static void trim_string(std::string &str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
}

void PhoneBook::search_contact(void)
{
	std::string buffer;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	int index = 0;

	std::cout << std::endl;
	std::cout << ">>>>>> * Search * <<<<<<" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < this->total; i++)
	{
		first_name = this->contacts[i].get_first_name();
		last_name = this->contacts[i].get_last_name();
		nickname = this->contacts[i].get_nickname();
		trim_string(first_name);
		trim_string(last_name);
		trim_string(nickname);
		std::cout << std::setw(10) << "Index: " << std::setw(10) << i << " | ";
		std::cout << std::setw(10) << "First name: " << std::setw(10) << first_name << " | ";
		std::cout << std::setw(10) << "Last name: " << std::setw(10) << last_name << " | ";
		std::cout << std::setw(10) << "Nickname: " << std::setw(10) << nickname << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, buffer);
	std::cout << std::endl;
	index = string_to_int(buffer);
	if (index >= 0 && index < this->total)
		this->contacts[index].print_contact();
	else
		std::cout << "Invalid index" << std::endl;
	std::cout << std::endl;
}
