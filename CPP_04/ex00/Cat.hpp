/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:33 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 11:35:35 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat :virtual public Animal
{
	public:

		Cat();
		// Cat(std::string name);
		// Cat(const Cat& src);
		~Cat();

		// Cat& operator=(const Cat& src);
		void makeSound() const;
};

#endif