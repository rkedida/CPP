/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:10 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/11 18:53:39 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete i;
// 	delete j;
// 	delete meta;

// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	const WrongAnimal* w_Animal = new WrongAnimal();
// 	const WrongAnimal* w_Cat = new WrongCat();

// 	w_Animal->makeSound();
// 	w_Cat->makeSound();
	
// 	delete w_Animal;
// 	delete w_Cat;

// 	return 0;
// }

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	// const Animal* arr[100];

	// for (int idx = 0; idx < 100; ++idx)
	// {
	// 	if (idx % 2 == 0)
	// 		arr[idx] = new Dog();
	// 	else
	// 		arr[idx] = new Cat();
	// }
	// for (int idx = 0; idx < 100; ++idx)
	// 	delete arr[idx];
	// ...
	return 0;
}