/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:32 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 12:14:52 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : virtual public Animal
{
	public:

		Dog();
		// Dog(std::string name);
		// Dog(const Dog& src);
		~Dog();

		// Dog& operator=(const Dog& src);
		void makeSound() const;
};

#endif