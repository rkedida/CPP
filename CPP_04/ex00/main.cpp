/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/12 18:39:50 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

// void leaks (void)
// {
// 	system("leaks Polymorphism");
// }

int main()
{
	// atexit(leaks);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* copy(j);

	std::cout << copy->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	std::cout << std::endl;

	const WrongAnimal* w_Animal = new WrongAnimal();
	const WrongAnimal* w_Cat = new WrongCat();

	w_Animal->makeSound();
	w_Cat->makeSound();
	
	delete w_Animal;
	delete w_Cat;

	return 0;
}
