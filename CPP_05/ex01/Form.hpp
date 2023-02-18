/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 16:49:21 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _RequiredGradeSign;
		const int _RequiredGradeExe;

	public:
		Form();
		Form(std::string name, bool nY, const int gradeSign, const int gradeExe);
		Form(const Form& src);
		~Form();

		Form& operator=(const Form& src);

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

		void beSigned(const Bureaucrat& src);

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExe() const;
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif