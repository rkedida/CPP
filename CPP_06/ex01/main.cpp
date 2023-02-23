/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/23 10:43:05 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialize.hpp"

int main()
{
	Data data;
	data.name = "Balu";
	data.id = 42;
	data.value = 3.14;

	uintptr_t raw = Serialize::serialize(&data);
	Data *ptr = Serialize::deserialize(raw);
	
	std::cout << "Name: " << ptr->name << std::endl;
	std::cout << "Id: " << ptr->id << std::endl;
	std::cout << "Value: " << ptr->value << std::endl;

	return (0);
}
