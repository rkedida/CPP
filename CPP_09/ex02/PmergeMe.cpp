/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:14:58 by rkedida           #+#    #+#             */
/*   Updated: 2023/05/24 20:51:23 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& src) : _v(src._v), _l(src._l)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		this->_v = src._v;
		this->_l = src._l;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::addNumber(double num)
{
	this->_v.push_back(num);
	this->_l.push_back(num);
}

void PmergeMe::printVector() const
{
	for (std::size_t i = 0; i < _v.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << _v[i];
	}
	std::cout << "\n";
}

void PmergeMe::printList() const
{
	std::list<int>::const_iterator it = _l.begin();
	if (it != _l.end())
	{
		std::cout << *it;
		++it;
	}
	for (; it != _l.end(); ++it)
		std::cout << " " << *it;
	std::cout << "\n";
}

void	PmergeMe::mergeInsertVector()
{
	timsortVector(_v.begin(), _v.end());
}

void PmergeMe::timsortVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	const int RUN = 32;
	int size = std::distance(begin, end);

	for (int i = 0; i < size; i += RUN)
		insertionSortVector(begin + i, std::min(begin + (i + RUN), end));
	for (int mid = RUN; mid < size; mid = 2 * mid)
	{
		for (int start = 0; start < size; start += 2 * mid)
		{
			std::vector<int>::iterator midIter = begin + std::min(start + mid, size);
			std::vector<int>::iterator endIter = begin + std::min(start + 2 * mid, size);
			mergeVector(begin + start, midIter, endIter);
		}
	}
}

void PmergeMe::insertionSortVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator i = begin; i != end; ++i)
	{
		int key = *i;
		std::vector<int>::iterator j = i;
		while (j > begin && *(j - 1) > key)
		{
			*j = *(j - 1);
			--j;
		}
		*j = key;
	}
}

void PmergeMe::mergeVector(std::vector<int>::iterator begin, std::vector<int>::iterator mid, std::vector<int>::iterator end)
{
	std::vector<int>::iterator leftIter = begin;
	std::vector<int>::iterator rightIter = mid;

	while (leftIter != mid && rightIter != end)
	{
		if (*leftIter <= *rightIter)
			++leftIter;
		else
		{
			std::vector<int>::iterator nextRightIter = rightIter;
			++nextRightIter;
			std::rotate(leftIter, rightIter, nextRightIter);
			++leftIter;
			++mid;
			++rightIter;
		}
	}
}


void	PmergeMe::mergeInsertList()
{
	timsortList(_l.begin(), _l.end());
}

void PmergeMe::timsortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	const int RUN = 32;
	int size = std::distance(begin, end);

	for (int i = 0; i < size; i += RUN)
	{
		std::list<int>::iterator iter = begin;
		std::advance(iter, i);
		std::list<int>::iterator iter_end = begin;
		std::advance(iter_end, std::min(i + RUN, size));
		insertionSortList(iter, iter_end);
	}
	for (int mid = RUN; mid < size; mid = 2 * mid)
	{
		for (int start = 0; start < size; start += 2 * mid)
		{
			std::list<int>::iterator startIter = begin;
			std::advance(startIter, start);
			std::list<int>::iterator midIter = begin;
			std::advance(midIter, std::min(start + mid, size));
			std::list<int>::iterator endIter = begin;
			std::advance(endIter, std::min(start + 2 * mid, size));
			mergeList(startIter, midIter, endIter);
		}
	}
}

void PmergeMe::insertionSortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	for (std::list<int>::iterator i = begin; i != end; ++i)
	{
		std::list<int>::iterator j = i;
		while (j != begin)
		{
			std::list<int>::iterator prevJ = j;
			--prevJ;
			if (*prevJ > *j)
			{
				std::iter_swap(j, prevJ);
				--j;
			}
			else
				break;
		}
	}
}

void PmergeMe::mergeList(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end)
{
	std::list<int>::iterator i = begin;
	std::list<int>::iterator j = mid;

	while (i != mid && j != end)
	{
		if (*i <= *j)
			++i;
		else
		{
			std::list<int>::iterator nextJ = j;
			++nextJ;
			std::rotate(i, j, nextJ);
			++i;
			++mid;
			++j;
		}
	}
}

bool	PmergeMe::check_check()
{
	if (!this->sorted(this->_v) || !this->sorted(this->_l))
		return false;
	return true;
}
