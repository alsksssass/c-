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
#include <deque>
typedef std::vector<std::pair<int, int> > vec_pair;
typedef std::vector<std::pair<int, int> >::iterator v_it;
typedef std::deque<std::pair<int, int> > dec_pair;
typedef std::deque<std::pair<int, int> >::iterator d_it;
class PmergeMe{
	private:
		vec_pair vec;
		dec_pair dec;
		PmergeMe(const PmergeMe &a);
		PmergeMe &operator=(const PmergeMe &a);
	public:
		PmergeMe();
		~PmergeMe();
		std::vector<int> make_temp(int argc, char **argv);
		void make_pair_index(int argc, std::vector<int> &arr);
		vec_pair req(vec_pair &arr,int n);		
		dec_pair req(dec_pair &arr,int n);
		int lower_bound(vec_pair &arr, int t, int low , int high);
		int lower_bound(dec_pair &arr, int t, int low , int high);
		static double c_time(void);
		vec_pair get_vec();
		dec_pair get_dec();
		
};