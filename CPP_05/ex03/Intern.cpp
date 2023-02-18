/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:55 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 13:47:03 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called." << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern Copy Constructor Called." << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called." << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
	std::cout << "Intern Copy Assignment Operator Called." << std::endl;
	(void) src;
	return *this;
}

AForm* Intern::makeForm(std::string nameForm, std::string target)
{
	AForm* form = nullptr;
	std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	// std::transform(nameForm.begin(), nameForm.end(), nameForm.begin(), ::tolower);

	int index;
	int index_c;

	for( index = 0; index < 3; index++)
	{
		if (formNames[index] == nameForm)
			break;
	}
	if (index == 3)
	{
		std::cout << "Invalid form name: " << nameForm << std::endl;
		return nullptr;
	}
	index_c = index;
	switch(index_c)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Invalid Argument." << std::endl;
			return nullptr;
	}
	std::cout << "Intern successfully created." << std::endl;
	return form;
}