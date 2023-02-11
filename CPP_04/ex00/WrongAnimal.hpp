/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 11:32:34 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>


class WrongAnimal
{
	private:
		std::string type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();

		virtual void makeSound() const;
};


#endif