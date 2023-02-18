/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 15:08:39 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat c("Khiroo", 140);
		Form a ("Balu", false, 140, 150);

		// Testing signing of a form
		c.signForm(a); // should succeed
		try
		{
			c.signForm(a); // should throw a Form::FormAlreadySigned exception
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// Testing grade validation when creating a Bureaucrat and a Form
		try
		{
			Bureaucrat d("BadGuy", 200); // should throw a Bureaucrat::GradeTooLowException exception
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Form b("BadForm", false, 0, 150); // should throw a Form::GradeTooHighException exception
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
