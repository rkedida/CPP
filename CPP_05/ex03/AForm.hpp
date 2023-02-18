/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 12:46:06 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _RequiredGradeSign;
		const int _RequiredGradeExe;

	public:
		AForm();
		AForm(std::string name, bool nY, const int gradeSign, const int gradeExe);
		AForm(const AForm& src);
		virtual ~AForm();

		AForm& operator=(const AForm& src);

		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};

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

		void execute(Bureaucrat const & executor) const;
		virtual void FormExecution() const = 0;

		void beSigned(const Bureaucrat& src);

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExe() const;
};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif