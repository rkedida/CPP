/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:30 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 11:36:28 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		// Animal(std::string name);
		// Animal(const Animal& src);
		virtual ~Animal();

		// Animal& operator=(const Animal& src);
		virtual void makeSound() const;

		std::string getType() const;
};

#endif