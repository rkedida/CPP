/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:50 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 11:40:20 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Khirooo", false, 145, 137)
{
	std::cout << "ShrubberyCreationForm Default Constructor Called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Khirooo", false, 145, 137)
{
	std::cout << "ShrubberyCreationForm Parametic Constructor Called." << std::endl;
	this->_target = target + "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "ShrubberyCreationForm Copy Assignment Operator Called." << std::endl;
	AForm::operator=(src);

	return *this;
}

void ShrubberyCreationForm::FormExecution() const
{
	std::ofstream file;
	
	file.open(this->_target);
	if(file.is_open())
	{
		file << "               ,@@@@@@@," << std::endl;
		file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		file << "    ,&\\%\\%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@8\\88888/88'" << std::endl;
		file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		file << "   %&&%/ %&\\%\\%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		file << "       |o|        | |         | |" << std::endl;
		file << "       |.|        | |         | |" << std::endl;
		file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Unable to open file." << std::endl;
	}
}
