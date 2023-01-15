/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:10:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 08:53:13 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include "HumanA.hpp"
# include "HumanB.hpp"

class Weapon
{
	private:
		std::string _type;

	public:
//		Constructor and destructor
		Weapon(std::string& type);
		~Weapon();

//		member functions get and set
		const std::string& getType();
		void setType(std::string& type);
};

#endif