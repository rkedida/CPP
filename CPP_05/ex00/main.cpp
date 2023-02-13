/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:23:21 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/13 14:29:06 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a = Bureaucrat();
	int input;

	std::cout << "Please type a number between 1 and 150." << std::endl;
	std::cin >> input;
	try
	{
		a.setGrade(input);
	}
	catch(const Bureaucrat& e)
	{
		a.GradeTooHighException();
	}
	return 0;
}