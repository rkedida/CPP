/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/24 21:45:12 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		unsigned int _nE;
		T* data;

	public:
		Array();
		Array(unsigned int nE);
		~Array();

		Array& operator=(const Array& src);
};

template <typename T>
Array<T>::Array() : _nE(0), ptrDataElm(0)
{
	std::cout << "Array Default Constructor Called." << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int nE) : _nE(nE)
{
	std::cout << "Array Parametic Constructor Called." << std::endl;
	this->data = new T[nE];
	for(unsigned int i = 0; i < this->nE; i++)
		this->data[i] = src.data[i];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Default Constructor Called." << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
	std::cout << "Array Copy Assignment Operator Called." << std::endl;
	if (this != src)
	{
		T* newData = new T[src._nE];
		for(unsigned int i = 0; i < src._nE; i++)
			newData[i] = src.data[i]

		delete [] data;
		data = newData;
		this->_ne = src._nE;
	}
}

template <typename T>


std::ostream operator<<(std::ostream& out, const Array& src)
{
	out << src.
}

#endif