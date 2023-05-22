#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <sys/time.h>
#include <algorithm>
#include <map>

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

};


#endif