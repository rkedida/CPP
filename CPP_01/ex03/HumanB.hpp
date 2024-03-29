/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:15:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/15 13:08:07 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"
# include "HumanA.hpp"

class Weapon;

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;

	public:

		HumanB(std::string name);
		~HumanB();

		void attack();
		void setWeapon(Weapon &_weapon);
		std::string getWeapon();
};

#endif