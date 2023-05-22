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
	this->_vInital.push_back(num);
	this->_l.push_back(num);
	this->_lInital.push_back(num);
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

void	PmergeMe::resetVectorList()
{
	this->_v = this->_vInital;
	this->_l = this->_lInital;
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
	std::vector<int> leftArray(mid - begin);
	std::vector<int> rightArray(end - mid);

	std::copy(begin, mid, leftArray.begin());
	std::copy(mid, end, rightArray.begin());

	std::vector<int>::iterator leftIter = leftArray.begin();
	std::vector<int>::iterator rightIter = rightArray.begin();

	for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
	{
		if (leftIter != leftArray.end() && (rightIter == rightArray.end() || *leftIter <= *rightIter))
		{
			*iter = *leftIter;
			++leftIter;
		}
		else
		{
			*iter = *rightIter;
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
		std::advance(iter, std::min(i + RUN, size));
		insertionSortList(begin, iter);
	}

	for (int mid = RUN; mid < size; mid = 2 * mid)
	{
		for (int start = 0; start < size; start += 2 * mid)
		{
			std::list<int>::iterator midIter = begin;
			std::list<int>::iterator endIter = begin;
			std::advance(midIter, std::min(start + mid, size));
			std::advance(endIter, std::min(start + 2 * mid, size));

			mergeList(begin, midIter, endIter);
		}
	}
}

void PmergeMe::insertionSortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	for (std::list<int>::iterator i = begin; i != end; ++i)
	{
		std::list<int>::iterator insert_point = std::lower_bound(begin, i , *i);
		std::rotate(insert_point, i, end);
	}
}

void PmergeMe::mergeList(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end)
{
	std::list<int> leftList(begin, mid);
	std::list<int> rightList(mid, end);

	std::list<int>::iterator it = begin;
	while (!leftList.empty() && !rightList.empty())
	{
		if (leftList.front() <= rightList.front())
		{
			*it++ = leftList.front();
			leftList.pop_front();
		}
		else
		{
			*it++ = rightList.front();
			rightList.pop_front();
		}
	}
	while (!leftList.empty())
	{
		*it++ = leftList.front();
		leftList.pop_front();
	}
	while (!rightList.empty())
	{
		*it++ = rightList.front();
		rightList.pop_front();
	}
}

