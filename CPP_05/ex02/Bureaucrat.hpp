/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:55 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/15 17:26:43 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& src);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void executeForm(AForm const & form);

		void signForm(AForm& src) const;

		void incrementGrade();
		void decrementGrade();

		void setGrade(const int grade);

		std::string getName() const;
		int getGrade() const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif