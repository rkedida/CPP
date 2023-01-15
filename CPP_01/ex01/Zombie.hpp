/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:28:04 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 01:29:29 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
//	Attributes
		std::string _name;

	public:
//	Constructor and Destructor
		Zombie();
		~Zombie();

//	Member functions
		void announce(void);
		void set_name(std::string name);
};

//	Non-member functions

Zombie* zombieHorde(int N, std::string name );

#endif