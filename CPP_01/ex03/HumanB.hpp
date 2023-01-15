/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:15:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 08:20:03 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"
# include "HumanA.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;

	public:
//		Constructor and destructor
		HumanB(std::string name);
		~HumanB();

//		member functions get and set
		void attack();
		void setWeapon(Weapon& weapon);
};

#endif