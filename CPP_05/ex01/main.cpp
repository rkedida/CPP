/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/15 15:33:42 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

// void leaks (void)
// {
// 	system("leaks Bureaucrat");
// }

// int main()
// {
// 	try
// 	{
// 		// atexit(leaks);
// 		Bureaucrat a = Bureaucrat();
// 		Form c;
// 		// Bureaucrat a = Bureaucrat("Khiroo", 152);
	
// 		int input;
	
// 		// a = b;
// 		std::cout << "Please type a number between 1 and 150." << std::endl;
// 		std::cin >> input;
// 		a.setGrade(input);
// 		// c.beSigned(a);
// 		a.signForm(c);
// 		std::cout << a;
// 		// std::cout << "This UserInput has a grade " << a.getGrade() << std::endl; 
// 		a.incrementGrade();
// 		a.setGrade(a.getGrade());
// 		std::cout << a;
// 		// std::cout << "Grade after increment: " << a.getGrade() << std::endl;
// 		a.decrementGrade();
// 		a.setGrade(a.getGrade());
// 		std::cout << a;
// 		// std::cout << "Grade after decrement: " << a.getGrade() << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return 0;
// }

int main()
{
	try
	{
		Bureaucrat c("Khiroo", 140);
		Form a ("Balu", false, 140, 150);

		c.signForm(a);
		c.signForm(a);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}