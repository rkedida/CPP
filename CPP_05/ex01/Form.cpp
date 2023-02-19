/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/19 12:29:54 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("Balu"), _signed(false), _RequiredGradeSign(1), _RequiredGradeExe(15)
{
	std::cout << "Form Default Constructor Called." << std::endl;
}

Form::Form(std::string name, bool nY, const int RequiredGradeSign, const int RequiredGradeExe) : _name(name), _signed(nY), _RequiredGradeSign(RequiredGradeSign), _RequiredGradeExe(RequiredGradeExe)
{
	std::cout << "Form Parametic Constructor Called." << std::endl;
	if (this->_RequiredGradeSign < 1 || this->_RequiredGradeExe < 1)
		throw GradeTooHighException();
	else if (this->_RequiredGradeSign > 150 || this->_RequiredGradeExe > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _RequiredGradeSign(src._RequiredGradeSign), _RequiredGradeExe(src._RequiredGradeExe)
{
	std::cout << "Form Copy Constructor Called." << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor Called." << std::endl;
}

Form& Form::operator=(const Form& src)
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

const char* Form::GradeTooHighException::what() const throw()
{
	return "Too HIGH!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Too LOW!";
}

void Form::beSigned(const Bureaucrat& src)
{
	int grade = src.getGrade();

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	if (this->_signed == true)
		std::cout << "This " << src.getName() << " already Signed the Form." << std::endl;
	if (grade <= this->_RequiredGradeSign)
	{
		this->_signed = true;
		std::cout << "This " << src.getName() << " signed the Form." << std::endl;
	}
	else
		std::cout << "This " << src.getName() << " can't Sign the Form." << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeSign() const
{
	return this->_RequiredGradeSign;
}

int Form::getGradeExe() const
{
	return this->_RequiredGradeExe;
}

std::ostream& operator<<(std::ostream& out, const Form& src)
{
	out << "This " << src.getName() << " Form needs at least a RequiredGradeSign of " << src.getGradeSign() << " and a RequiredGradeExe of " << src.getGradeExe() << "." << std::endl;
	return out;
}
