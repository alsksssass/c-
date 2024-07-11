#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
		return 0;
	PmergeMe p;
	std::vector<std::pair<int,int> > temp;
	std::vector<int> a = p.make_temp(argc,argv);
	temp = p.make_pair_index(argc,a);
	if(temp.size() < 1)
		return 0;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		std::cout << temp[i].first << " " << temp[i].second << std::endl;
	}
	double  st = PmergeMe::c_time();	
	std::vector<std::pair<int,int> > ret = p.req(temp,1);
	double  ed = PmergeMe::c_time();
	std::cout << "time = " << std::fixed << std::setprecision(5) <<  (ed - st)<< std::endl;
	std::sort(a.begin(),a.end());
	std::cout <<std::endl << "result  == " << std::endl;
	for(unsigned int i = 0; i < ret.size(); i++)
	{
		if(ret[i].first != a[i])
		{
			std::cout << "idx i = " << i << "ret = " << ret[i].first << " a[i] " << a[i] << std::endl;
			std::cout << "not sorted !!" << std::endl;
			for(unsigned int i = 0; i < ret.size(); i++)
			{
				// std::cout << "idx i = " << i << "ret = " << ret[i].first << " a[i] " << a[i] << std::endl; 
				std::cout << "idx i = " << i << "ret = " << ret[i].first << std::endl; 
			}
			break;
		}
	}
	return 0;
}