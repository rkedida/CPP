/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:35:47 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/12 23:56:01 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name );
		~Zombie();

		void announce( void );
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif