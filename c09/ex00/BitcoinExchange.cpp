#include "BitcoinExchange.hpp"

bool vaild_day(int y,int m, int d)
{
	int max_day = 30;
	if(m  < 1 || m > 12)
		return false;
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		max_day = 31;
	if(m == 2)
	{
		if((y %4 == 0 && y % 100 !=0) || y %400 == 0)
			max_day = 29;
		else
			max_day = 28;
	}
	if(d < 1 || d >max_day)
		return false;
	return true;
}
bool date_check(const std::string &s)
{
	if(s.size()!= 10)
		return false;
	for(unsigned int i = 0; i < s.size(); i++)
	{
		if(!isdigit(s[i]))
		{
			if((i == 4 || i == 7) && s[i] == '-')
				continue;
			return false;
		}
		if(i == 4 || i == 7)
			return false;
	}
	char *ptr;
	int y = strtod((s.substr(0,4)).c_str(),&ptr); 
	int month = strtod((s.substr(5,6)).c_str(),&ptr);
	int day = strtod((s.substr(8,9)).c_str(),&ptr);
	if(vaild_day(y,month,day) == false)
		return false;
	return true;
}
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
void BitcoinExchange::getbase(const std::string &database_name){
	std::string path = "./" + database_name;
	std::ifstream file(path.c_str());
	if(!file.is_open())
		throw std::invalid_argument("file_open_error");
	
	std::string data;
	while(1)
	{
		getline(file,data);
		if(data.empty())
			break;
		if(data == "date | value")
			continue;
		if(data.size() < 11 || data.find(',') == std::string::npos || data.find(',') != 10)
			std::invalid_argument("error : database");
		std::string date = data.substr(0,10);
		std::string value = data.substr(11);
		char *ptr = 0;
		double price = strtod(value.c_str(),&ptr);
		if(date_check(date) == false || *ptr != 0)
			std::invalid_argument("error : database");
		sdata.insert(std::make_pair(date,price));
	}
}
double BitcoinExchange::findData(const std::string &a){
	double ret;
	if(date_check(a) == false || sdata.empty())
		throw std::invalid_argument("data_find_error");
	std::map<std::string, double>::iterator it = sdata.find(a);
	if(it == sdata.end())
	{
		it = sdata.lower_bound(a);
		if(it == sdata.begin())
			throw std::out_of_range("no_data");
		--it;
		ret = it->second;
		return ret;
	}
	ret = it->second;
	return ret;
}
void BitcoinExchange::getinput(const std::string &database_name){
	std::string path = "./" + database_name;
	std::ifstream file(path.c_str());
	if(!file.is_open())
		throw std::invalid_argument("file_open_error");
	
	std::string data;
	while(1)
	{
		if(file.eof())
			break;
		getline(file,data);
		if(data == "date | value" || data == "")
			continue;
		if(data.size() < 14 || data.empty() || data.find('|') != 11)
		{
			std::cout << "Error: bad input => " << data << std::endl;
			continue;
		}
		std::string date = data.substr(0,10);
		if(date_check(date) == false)
		{
			std::cout << "Error: bad input => " << data << std::endl;
			continue;
		}
		std::string value = data.substr(13);			
		char *ptr = 0;
		double price = strtod(value.c_str(),&ptr);
		if(*ptr != 0)
		{
			std::cout << "Error: not number" << value << std::endl;;
			continue;
		}
		else if (price > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;;
			continue;
		}
		else if (price < 0)
		{
			std::cout << "Error: not a positive number."<< std::endl;
			continue;
		}
		double get_num= findData(date);
		double ret = get_num * price;

		std::cout << date << " => " << price << " = " << ret << std::endl;
	}
}
