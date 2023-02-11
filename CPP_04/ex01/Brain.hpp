/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 19:41:25 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	protected:
		std::string* ideas;

	public:
		Brain();
		Brain(const Brain& src);
		~Brain();

		Brain& operator=(const Brain& src);
};

#endif