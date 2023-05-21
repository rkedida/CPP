#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

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

void	PmergeMe::mergeInsertVector()
{
	for (std::size_t i = 1; i < _v.size(); ++i)
	{
		int key = _v[i];
		std::size_t j = i;
		while (j > 0 && _v[j - 1] > key) {
			_v[j] = _v[j - 1];
			--j;
		}
		_v[j] = key;
	}
}

void	PmergeMe::mergeInsertList()
{
	if (_l.size() <= 1)
		return; // Already sorted

	std::list<int>::iterator it = _l.begin();
	++it; // Start from the second element
	for (; it != _l.end(); ++it)
	{
		int key = *it;
		std::list<int>::iterator it2 = it;
		--it2; // Start comparing with the previous element
		while (it2 != _l.begin() && *it2 > key)
		{
			std::swap(*it2, *(std::next(it2)));
			--it2;
		}
		if (*it2 > key)
			std::swap(*it2, *(std::next(it2)));
	}
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

