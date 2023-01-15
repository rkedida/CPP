/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:06:22 by rkedida           #+#    #+#             */
/*   Updated: 2023/01/13 08:54:39 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"
# include "HumanB.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon _weapon;

	public:
		HumanA(std::string& name, Weapon& weapon);
		~HumanA();

		void attack();
};

#endif