/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 16:40:08 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		// Create instances of each form type
		ShrubberyCreationForm a("home");
		PresidentialPardonForm b("hallo");
		RobotomyRequestForm c("Khirooo");

		// Create instances of each bureaucrat with varying grades
		Bureaucrat Balu1("Robel1", 1);
		Bureaucrat Balu2("Robel2", 20);
		Bureaucrat Balu3("Robel3", 150);

		// Testing signForm() function
		std::cout << std::endl;
		Balu1.signForm(a);
		a.beSigned(Balu1);
		a.execute(Balu1);
		std::cout << std::endl;
		Balu2.signForm(b);
		b.beSigned(Balu2);
		b.execute(Balu2);
		std::cout << std::endl;
		Balu3.signForm(c);
		c.beSigned(Balu3);
		c.execute(Balu3);

		std::cout << Balu1 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
