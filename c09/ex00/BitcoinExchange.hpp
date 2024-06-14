#pragma once
#include <map>
#include <iostream>
class BitcoinExchange{
	private:
		std::map<std::string,int> data;
		BitcoinExchange(BitcoinExchange const &a);
		BitcoinExchange& operator=(BitcoinExchange const &a);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void getData(const std::string &a);
		int findData(const std::string &a);
		};