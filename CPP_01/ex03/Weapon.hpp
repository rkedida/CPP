/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:10:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/15 13:10:35 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include "HumanA.hpp"
# include "HumanB.hpp"

class HumanA;
class HumanB;

class Weapon
{
	private:
		std::string _type;

	public:

		Weapon(std::string type);
		~Weapon();

		void setType(std::string type);
		const std::string& getType();
};

#endif