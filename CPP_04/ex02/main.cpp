/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 18:44:38 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"

#define nb 100

void leaks (void)
{
	system("leaks WorldOnFire");
}

int main()
{
	atexit(leaks);
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << std::endl;


	const Animal* arr[nb];

	for (int idx = 0; idx < nb; ++idx)
	{
		if (idx % 2 == 0)
			arr[idx] = new Dog();
		else
			arr[idx] = new Cat();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int idx = 0; idx < nb; ++idx)
		delete arr[idx];

	return 0;
}
