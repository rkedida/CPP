/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:30 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 16:35:56 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		Brain* brain;

	public:
		Animal();
		virtual ~Animal();
	
		virtual void makeSound() const;

		std::string getType() const;
};

#endif