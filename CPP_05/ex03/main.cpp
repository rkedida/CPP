/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 14:03:45 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main()
{
	try
	{
		// Create instances of each form type
		ShrubberyCreationForm a("home");
		PresidentialPardonForm b("hallo");
		RobotomyRequestForm c("Khirooo");

		// // Create instances of each bureaucrat with varying grades
		Bureaucrat Balu1("Robel1", 1);
		Bureaucrat Balu2("Robel2", 1);
		Bureaucrat Balu3("Robel3", 1);

		// Have each bureaucrat sign and execute a form
		Balu1.signForm(b);
		b.execute(Balu1);

		Balu2.signForm(a);
		a.execute(Balu2);

		Balu3.signForm(c);
		c.execute(Balu3);

		// Have each bureaucrat execute a form directly
		Balu1.executeForm(b);
		Balu2.executeForm(a);
		Balu3.executeForm(c);

		// Attempt to create a ShrubberyCreationForm with an invalid target
		// This should throw a Form::GradeTooHighException exception
		try
		{
			ShrubberyCreationForm d("");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		// Attempt to create a Bureaucrat with an invalid grade
		// This should throw a Bureaucrat::GradeTooLowException exception
		try
		{
			Bureaucrat Balu4("Robel", 200);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		// Attempt to execute a form with a bureaucrat that does not have
		// sufficient grade to do so
		// This should throw a Form::GradeTooLowException exception
		try
		{
			Balu3.executeForm(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "------------------INTERN TEST ------------------" << std::endl;
		// Test the Intern class
		Intern intern;

		// Test creating each form using the Intern class wrong
		// AForm* form1 = intern.makeForm("shrubbery creation", "tree");
		// AForm* form2 = intern.makeForm("presidential pardon", "criminal");
		// AForm* form3 = intern.makeForm("robotomy request", "robot");

		// Test creating each form using the Intern class correct
		AForm* form1 = intern.makeForm("ShrubberyCreationForm", "tree");
		AForm* form2 = intern.makeForm("RobotomyRequestForm", "criminal");
		AForm* form3 = intern.makeForm("PresidentialPardonForm", "robot");

		// Test when Form is signed
		Balu1.signForm(*form1);
		Balu2.signForm(*form2);
		Balu3.signForm(*form3);


		// Test executing each form using a bureaucrat
		if (form1 != nullptr)
			Balu1.executeForm(*form1);
		if (form2 != nullptr)
			Balu2.executeForm(*form2);
		if (form3 != nullptr)
			Balu3.executeForm(*form3);

		// Attempt to create an invalid form using the Intern class
		// This should return a nullptr
		AForm* form4 = intern.makeForm("invalid form", "target");

		if (!form4)
			std::cout << "Failed to create invalid form" << std::endl;

		// Delete each form to avoid memory leaks
		delete form1;
		delete form2;
		delete form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
