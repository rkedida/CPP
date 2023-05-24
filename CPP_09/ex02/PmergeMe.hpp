/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/05/24 20:51:14 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <iterator>
#include <sys/time.h>
#include <algorithm>
#include <map>

class PmergeMe
{
	private:
		std::vector<int> _v;
		std::list<int> _l;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		void	addNumber(double num);
		void	printVector() const;
		void	printList() const;
		void	resetVectorList();

		void	mergeInsertVector();
		void timsortVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void insertionSortVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void mergeVector(std::vector<int>::iterator begin, std::vector<int>::iterator mid, std::vector<int>::iterator end);

		void	mergeInsertList();
		void timsortList(std::list<int>::iterator begin, std::list<int>::iterator end);
		void insertionSortList(std::list<int>::iterator begin, std::list<int>::iterator end);
		void mergeList(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end);

		bool check_check();
		template<typename T>
		bool	sorted(T const & container)
		{
			typename T::const_iterator it;
			typename T::const_iterator temp;
			for (it = container.begin(); it != container.end(); ++it)
			{
				temp = it;
				std::advance(temp, 1);
				if (temp != container.end() && *it <= *temp)
					continue;
				break;
			}
			if (temp == container.end())
			{
				std::cout << "sorted: OKKK" << std::endl;
				return true;
			}
			std::cerr << "You should not see this!" << std::endl;
			return false;
		}
};

#endif