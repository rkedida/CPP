/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:50 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 11:39:51 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45)
{
	std::cout << "RobotomyRequestForm Default Constructor Called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45)
{
	std::cout << "RobotomyRequestForm Parametic Constructor Called." << std::endl;
	this->_target = target + "_shrubbery";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src)
{
	std::cout << "RobotomyRequestForm Copy Constructor Called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called." << std::endl;
	AForm::operator=(src);

	return *this;
}

void RobotomyRequestForm::FormExecution() const
{
	if (rand() % 2)
		std::cout << "This has been robotomized successfully." << std::endl;
	else
		std::cout << "the robotomy failed." << std::endl;
}
