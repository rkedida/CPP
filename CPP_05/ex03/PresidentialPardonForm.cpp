/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:50 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 10:36:57 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5)
{
	std::cout << "PresidentialPardonForm Default Constructor Called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5)
{
	std::cout << "PresidentialPardonForm Parametic Constructor Called." << std::endl;
	this->_target = target + "_shrubbery";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "PresidentialPardonForm Copy Assignment Constructor Called." << std::endl;
	AForm::operator=(src);

	return *this;
}

void PresidentialPardonForm::FormExecution() const
{
	std::cout << "This has been pardoned by Zaphod Beeblebrox." << std::endl;
}
