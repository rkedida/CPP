/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/15 16:57:38 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Balu"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	std::cout << "Bureaucrat Parametic Constructor Called." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat Copy Constructor Called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor Called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Bureaucrat Copy Assignment Operator Called." << std::endl;
	this->_grade = src._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Too HIGH!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Too LOW!";
}

void Bureaucrat::signForm(AForm& src) const
{
	if (this->_grade <= src.getGradeSign())
	{
		if (src.getSigned() == false)
			src.beSigned(*this);
		else
			std::cout << "This " << this->_name << " already Signed the Form." << std::endl;
	}
	else
		std::cout << "This " << this->_name << " can't Sign " << src.getName() << " because the Grade is too Low!" << std::endl;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}

void Bureaucrat::setGrade(const int grade)
{
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src)
{
	out << "This " << src.getName() << " Bureaucrat grade " << src.getGrade() << std::endl;
	return out;
}
