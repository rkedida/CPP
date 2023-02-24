/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/24 18:09:02 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T,typename F>
void iter(T* arr, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template<typename T>
void print(const T& m)
{
	std::cout << m << std::endl;
	return ;
}

class Iter
{
	private:
		int _i;

	public:
		Iter() : _i(26) {};
		int get() const {return this->_i;}

};

std::ostream& operator<<(std::ostream& out, const Iter src) { out << src.get(); return out;}

#endif