#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> _v, _vInital;
		std::list<int> _l, _lInital;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		void	addNumber(double num);
		void	mergeInsertVector();
		void	mergeInsertList();

		void	printVector() const;
		void	printList() const;
		void	resetVectorList();

};


#endif