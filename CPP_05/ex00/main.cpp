/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/14 11:35:55 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void leaks (void)
{
	system("leaks Bureaucrat");
}

int main()
{
	try
	{
		atexit(leaks);
		Bureaucrat a = Bureaucrat();
		// Bureaucrat a = Bureaucrat("Khiroo", 152);
	
		int input;
	
		// a = b;
		std::cout << "Please type a number between 1 and 150." << std::endl;
		std::cin >> input;
		a.setGrade(input);
		std::cout << a;
		// std::cout << "This UserInput has a grade " << a.getGrade() << std::endl; 
		a.incrementGrade();
		a.setGrade(a.getGrade());
		std::cout << a;
		// std::cout << "Grade after increment: " << a.getGrade() << std::endl;
		a.decrementGrade();
		a.setGrade(a.getGrade());
		std::cout << a;
		// std::cout << "Grade after decrement: " << a.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
