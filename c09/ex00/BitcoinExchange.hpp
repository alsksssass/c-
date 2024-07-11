#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <utility>
class BitcoinExchange
{
private:
	std::map<std::string, double> sdata;
	std::map<std::string, double> input_data;
	BitcoinExchange(BitcoinExchange const &a);
	BitcoinExchange &operator=(BitcoinExchange const &a);

public:
	BitcoinExchange();
	~BitcoinExchange();
	void getbase(const std::string &database_name);
	void getinput(const std::string &database_name);
	double findData(const std::string &a);
};