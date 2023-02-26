/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/26 09:11:07 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <ostream>

template <typename T>
class Array
{
	private:
		unsigned int _nE;
		T* data;

	public:
		Array() : _nE(0), data(new T[0])
		{
			std::cout << "Array Default Constructor Called." << std::endl;
		}

		Array(unsigned int nE) : _nE(nE), data(new T[nE])
		{
			std::cout << "Array Parametic Constructor Called." << std::endl;
		}

		Array(const Array& src)
		{
			std::cout << "Array Copy Constructor Called." << std::endl;
			*this = src;
		}

		~Array()
		{
			delete [] data;
			std::cout << "Array Destructor Called." << std::endl;
		}

		Array& operator=(const Array& src)
		{
			std::cout << "Array Copy Assignment Operator Called." << std::endl;
			if (this != &src)
			{
				T* newData = new T[src._nE];
				for(unsigned int i = 0; i < src.size(); i++)
					newData[i] = src.data[i];
		
				delete [] data;
				data = newData;
				this->_nE = src._nE;
			}
			return *this;
		}

		T& operator[](unsigned int nE)
		{
			 if (nE >= this->_nE)
				throw std::out_of_range("Invalid index");
			return data[nE];
		}

		T* getData() const {return this->data;}
		unsigned int size() const 
		{
			return this->_nE;
		}

};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& src)
{
	out << "[ ";
	for (unsigned int i = 0; i < src.size(); i++)
		out << "'" << src.getData()[i] << "'" << " ";
	out << "]";

	return out;
}

#endif