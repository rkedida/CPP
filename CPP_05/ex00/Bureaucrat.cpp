/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/13 15:14:21 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <string>
# include <exception>

Bureaucrat::Bureaucrat() : _name("Balu"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Parametic Constructor Called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat Copy Constructor Called." << std::endl;
	*this = src;
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

const char* Bureaucrat::GradeTooHighException()
{
	return "Too HIGH!";
}

const char* Bureaucrat::GradeTooLowException()
{
	return "Too LOW!";
}

void Bureaucrat::setGrade(int grade)
{
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade < 1)
		throw this->GradeTooLowException();
	else if (grade > 150)
		throw this->GradeTooLowException();
}

std::string Bureaucrat::getName()
{
	return this->_name;
}

int Bureaucrat::getGrade()
{
	return this->_grade;
}

std::ostream& ostream::operator<<(std::ostream& out, const Bureaucrat* src)
{
	
}
