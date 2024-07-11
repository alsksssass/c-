#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
		return 0;
	PmergeMe p;
	std::vector<std::pair<int,int> > temp;
	std::vector<int> a = p.make_temp(argc,argv);
	std::cout << "before sort = ";
	for(unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	p.make_pair_index(argc,a);
	vec_pair vec_temp = p.get_vec();
	double  st = PmergeMe::c_time();
	vec_pair ret_vec = p.req(vec_temp,1);
	double  ed = PmergeMe::c_time();
	std::cout <<std::endl << "sorted vector arr = ";
	for(unsigned int i = 0; i < ret_vec.size(); i++)
		std::cout << ret_vec[i].first << " ";
	
	std::cout << std::endl << "time = " << std::fixed << std::setprecision(5) <<  (ed - st) << " us"<< std::endl;

	dec_pair dec_temp = p.get_dec();
	st = PmergeMe::c_time();
	dec_pair ret_dec = p.req(dec_temp,1);
	ed = PmergeMe::c_time();
	std::cout << "sorted decque arr = ";
	for(unsigned int i = 0; i < ret_dec.size(); i++)
		std::cout << ret_dec[i].first << " ";
	
	std::cout << std::endl << "time = " << std::fixed << std::setprecision(5) <<  (ed - st)<< " us" << std::endl;


	std::sort(a.begin(),a.end());
	std::cout <<std::endl << "result  == " << std::endl;
	for(unsigned int i = 0; i < ret_dec.size(); i++)
	{
		if(ret_dec[i].first != a[i] ||  ret_vec[i].first != a[i])
		{
			std::cout << "not sorted !!" << std::endl;
			break;
		}
	}
	return 0;
}