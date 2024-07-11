#pragma once
#include <vector>
#include <utility>
#include <list>
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <algorithm>
#include <cmath>
#include <iomanip>


class PmergeMe{
	private:
		std::vector<std::pair<int,int> > vt;
		std::list<std::pair<int, int> > lst;
		PmergeMe(const PmergeMe &a);
		PmergeMe &operator=(const PmergeMe &a);
	public:
		PmergeMe();
		~PmergeMe();
		void time_stamp() const;
		std::vector<int> make_temp(int argc, char **argv);
		std::vector<std::pair<int, int> > make_pair_index(int argc, std::vector<int> &arr);
		std::vector<std::pair<int, int> > req(std::vector<std::pair<int, int> > &arr,int n);
		static double c_time(void);
		
};