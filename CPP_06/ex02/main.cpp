/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/23 15:45:29 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base* generate()
{
	int x = std::rand() % 3;
	A* a;
	B* b;
	C* c;

	switch(x)
	{
		case 0:
			a = new A();
			std::cout << "Generated A" << std::endl;
			return a;
		case 1:
			b = new B();
			std::cout << "Generated B" << std::endl;
			return b;
		case 2:
			c = new C();
			std::cout << "Generated C" << std::endl;
			return c;
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C" << std::endl;
	else
		std::cout << "UNKNOWN" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Identified A" << std::endl;
		(void)a;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Identified B" << std::endl;
		(void)b;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Identified C" << std::endl;
		(void)c;
		return;
	}
	catch(const std::bad_cast& e)
	{
	}
}

int main()
{
	std::srand(std::time(nullptr));
	Base *p = generate();

	identify(p);
	identify(*p);

	delete p;
	return 0;
}
