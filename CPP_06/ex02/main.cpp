/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/23 14:10:46 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

const char* Unknown::what() const throw()
{
	return "UNKNOWN";
}

Base* generate()
{
	int x = std::rand() % 3;
	A* a;
	B* b;
	C* c;


	try
	{
		switch(x)
		{
			case 0:
			a = new A();
			return a;
			case 1:
			b = new B();
			return b;
			case 2:
			c = new C();
			return c;
			default:
				throw Unknown();
		}
	}
	catch(const Unknown& e)
	{
		return nullptr;
		std::cerr << e.what() << '\n';
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "UNKNOWN" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;

		return;
	}
	catch(const Unknown& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(const Unknown& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(const Unknown& e)
	{
		std::cerr << e.what() << std::endl;
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