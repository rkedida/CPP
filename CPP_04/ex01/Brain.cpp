/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 19:46:26 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called." << std::endl;
	ideas = new std::string [100];
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain Copy Constructor Called." << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called." << std::endl;
	delete [] ideas;
}

Brain &Brain::operator=(const Brain& src)
{
	std::cout << "Brain Copy Assignment Operator Called." << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = src.ideas[i];
	return *this;
}
