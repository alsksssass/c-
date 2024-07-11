#include "PmergeMe.hpp"
double PmergeMe::c_time(void)
{
	struct timeval	timeval_time;
	long long		result;

	gettimeofday(&timeval_time, 0);
	result = (timeval_time.tv_sec * 1000000) + (timeval_time.tv_usec);
	return (result);
}
long long find_ya(int idx)
{
	if(idx > 18 || idx < 0)
		throw std::invalid_argument("error yacop");
	long long arr[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	return arr[idx] -1;
}

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){
}
std::vector<int> PmergeMe::make_temp(int argc, char **argv)
{
	std::vector<int> temp;
	for(int i =1; i < argc; i++)
	{
		int a;
		a = std::atoi(argv[i]);
		temp.push_back(a);
	}
	return temp;
}
std::vector<std::pair<int, int> > PmergeMe::make_pair_index(int argc, std::vector<int> &arr)
{
	std::vector<std::pair<int, int> > temp;
	for(int i = 1; i < argc; i++)
		temp.push_back(std::make_pair(arr[i-1],i-1));
	return temp;
}
void PmergeMe::time_stamp() const{
	double  st = c_time();
	long a = 0;
	for(long i = 0; i < 1000000; i++)
		a = i;
	double  ed = c_time();

	std::cout << (ed - st)<< std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::req(std::vector<std::pair<int, int> > &arr,int n){
	if(arr.size() == 1)
		return arr;
	std::vector<std::pair<int, int> > lage_num;
	std::vector<std::pair<int, int> > small_num;
	std::vector<std::pair<int, int> > temp;
	for(unsigned int i = 0; i < arr.size()-1; i+=2)
	{
		arr[i].first > arr[i+1].first ? lage_num.push_back(arr[i]) : small_num.push_back(arr[i]);
		arr[i].first <= arr[i+1].first ? lage_num.push_back(arr[i+1]) : small_num.push_back(arr[i+1]);
	}
	if(arr.size()%2)
		small_num.push_back(arr[arr.size()-1]);
	lage_num =req(lage_num,n+1);
	int n_pow = std::pow(2, n);
	for (int i = 0; i < (int)lage_num.size(); i++)
		temp.push_back(small_num[lage_num[i].second / n_pow]);
	if (arr.size() % 2)
		temp.push_back(small_num[small_num.size() - 1]);
	// std::cout << "temp list " << std::endl;
	// for (unsigned int i = 0; i < temp.size(); i++)
	// 	std::cout << temp[i].first << std::endl;

	// std::cout << "lage list " << std::endl;
	// for (unsigned int i = 0; i < lage_num.size(); i++)
	// 	std::cout << lage_num[i].first << std::endl;
	int k = 0;
	for (int i = 1; i < 19; i++)
	{
		long long ya_curr = std::min((int)find_ya(i), (int)(temp.size() > lage_num.size() ? temp.size() : lage_num.size()));
		long long ya_prev = find_ya(i - 1);
		for (long long j = ya_curr; j > ya_prev; j--)
		{
			if (j + k > ((long long)lage_num.size()))
			{
				if (j - 1 == (int)temp.size() - 1)
				{
					std::vector<std::pair<int, int> >::iterator it;
					// it = std::lower_bound(lage_num.begin(), lage_num.end(), temp[j - 1]);
					it = lage_num.begin() + PmergeMe::lower_bound(lage_num,temp[j - 1].first,0,lage_num.size());
					lage_num.insert(it, temp[j - 1]);
				}
				continue;
			}
			unsigned int insert_index = (unsigned int)(j - 1);
			if (insert_index > temp.size() - 1)
				continue;
			std::vector<std::pair<int, int> >::iterator it;
			// it = std::lower_bound(lage_num.begin(), lage_num.begin() + j + k, temp[insert_index]);
			it = lage_num.begin() + PmergeMe::lower_bound(lage_num,temp[insert_index].first ,0 , j+k);
			lage_num.insert(it, temp[insert_index]);
			k++;
		}
		if ((int)(temp.size()) < (int)find_ya(i))
			break;
	}
	return lage_num;
}
typedef std::vector<std::pair<int, int> > vec_pair;
typedef std::vector<std::pair<int, int> >::iterator it;
int PmergeMe::lower_bound(vec_pair &arr, int t, int low, int high)
{
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].first< t)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

void PmergeMe::test(std::vector<std::pair<int, int> > &temp)
{
	int x = 6;
	std::vector<std::pair<int, int> >::iterator it;
	// it = std::lower_bound(lage_num.begin(), lage_num.end(), temp[j - 1]);
	int pos = PmergeMe::lower_bound(temp,x,0,temp.size()-1);
	std::cout << temp[pos].first <<  "pos = " << pos <<std::endl;
	temp.insert(temp.begin() + pos,std::make_pair(x,0));
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		std::cout << temp[i].first << std::endl;
	}
}