/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:33 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 15:08:04 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : virtual public Animal
{
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat& src);
		~Cat();

		Cat& operator=(const Cat& src);

		void makeSound() const;
};

#endif