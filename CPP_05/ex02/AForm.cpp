/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/15 17:05:09 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : _name("Balu"), _signed(false), _RequiredGradeSign(1), _RequiredGradeExe(15)
{
	std::cout << "Form Default Constructor Called." << std::endl;
}

AForm::AForm(std::string name, bool nY, const int RequiredGradeSign, const int RequiredGradeExe) : _name(name), _signed(nY), _RequiredGradeSign(RequiredGradeSign), _RequiredGradeExe(RequiredGradeExe)
{
	std::cout << "Form Parametic Constructor Called." << std::endl;
	if (this->_RequiredGradeSign < 1 || this->_RequiredGradeExe < 1)
		throw GradeTooHighException();
	else if (this->_RequiredGradeSign > 150 || this->_RequiredGradeExe > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src._name), _signed(src._signed), _RequiredGradeSign(src._RequiredGradeSign), _RequiredGradeExe(src._RequiredGradeExe)
{
	std::cout << "Form Copy Constructor Called." << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form Destructor Called." << std::endl;
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << "Form Copy Assignment Operator Called." << std::endl;
	int gradeSign = src.getGradeSign();
	int gradeExe = src.getGradeExe();

	if (gradeSign < 1 || gradeExe < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExe > 150)
		throw GradeTooLowException();
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Too HIGH!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Too LOW!";
}

// void AForm::beSigned(const Bureaucrat& src)
// {
// 	int grade = src.getGrade();

// 	if (grade < 1)
// 		throw GradeTooHighException();
// 	if (grade > 150)
// 		throw GradeTooLowException();
// 	if (grade <= this->_RequiredGradeSign)
// 	{
// 		this->_signed = true;
// 		std::cout << "This " << src.getName() << " signed the Form." << std::endl;
// 	}
// 	else
// 		std::cout << "This " << src.getName() << " can't Sign the Form." << std::endl;
// }

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeSign() const
{
	return this->_RequiredGradeSign;
}

int AForm::getGradeExe() const
{
	return this->_RequiredGradeExe;
}

std::ostream& operator<<(std::ostream& out, const AForm& src)
{
	out << "This " << src.getName() << " Form needs at least a RequiredGradeSign of " << src.getGradeSign() << " and a RequiredGradeExe of " << src.getGradeExe() << "." << std::endl;
	return out;
}
