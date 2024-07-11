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

typedef std::vector<std::pair<int, int> > vec_pair;
typedef std::vector<std::pair<int, int> >::iterator vec_it;
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
		vec_pair make_pair_index(int argc, std::vector<int> &arr);
		vec_pair req(vec_pair &arr,int n);
		int lower_bound(vec_pair &arr, int t, int low , int high);
		static double c_time(void);
		void test(std::vector<std::pair<int, int> > &temp);
		
};