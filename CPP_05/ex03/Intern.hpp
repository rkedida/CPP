/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:55 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/18 12:46:12 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "AForm.hpp"


class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();

		Intern& operator=(const Intern& src);

		AForm* makeForm(std::string nameForm, std::string target);
};

#endif