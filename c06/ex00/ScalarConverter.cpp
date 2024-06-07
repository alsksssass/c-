#include "ScalarConverter.hpp"
#include <cstdlib>
#include <sstream>

bool double_sign(std::string &str)
{
	bool check = false;
	for(int i =0; i < (int)str.size(); i++)
	{
		if(str[i] == '-' || str[i] == '+')
		{
			if(check == true)
				return true;
			check = true;
		}
	}
	return false;
}

bool all_char(std::string &str)
{
	for(int i =0; i < (int)str.size(); i++)
	{
		if(isdigit(str[i]))
			return false;
	}
	return true;
}

void ScalarConverter::convert(std::string str){
	if(str.empty())
		return;
	char *endp = NULL;
	bool out_of_range = false;
	double ptrd = 0;
	if(str.size() > 2 || (isdigit(str[0]) && str.size() ==1 ))
		ptrd = strtod(str.c_str(),&endp);
	else
	{
		int tmp = atoi(str.c_str());
		std::cout << tmp << std::endl;
		// if(!str.empty() && (tmp >= 0 && tmp < 128)):w
		ptrd = static_cast<double>(tmp);
	}
	std::string end_str = "";
	std::stringstream temp;
	if(endp != NULL)
		end_str = endp;
	for(int i = 0; i < (int)end_str.size(); i++)
		end_str[i] = std::tolower(end_str[i]);
	if((double_sign(str) == true) || (str.find(".") != std::string::npos && (str[str.find(".") +1] == 0 || !isdigit(str[str.find(".")+1]))))
	{
		std::cout << "error str" << std::endl;
		return ;
	}
	if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "nan" || str == "nanf" || str == "inf" || str == "inff" )
		out_of_range = true;
	if(out_of_range == false && str.size() > 1 && all_char(str) == true)
	{
		std::cout << "error str" << std::endl;
		return ;
	}
	char ptrc = static_cast<char>(ptrd);
	int ptri = static_cast<int>(ptrd);
	float ptrf = static_cast<float>(ptrd);
	(std::isprint(ptrd) && !out_of_range) ? std::cout <<"char = \'" << ptrc <<"\'"<< std::endl : (out_of_range || ptrd < 0 || ptrd > 127) ? std::cout <<"char = " << "impossible" << std::endl : std::cout <<"char = " << "not printalbe" << std::endl;
	(out_of_range || (ptrd > 2147483647.0 || ptrd < -2147483648.0)) ? std::cout <<"int = " << "impossible" << std::endl : std::cout <<"int = " << ptri << std::endl; 
	temp << ptrf;
	(out_of_range) ? std::cout <<"float = " << ptrf <<"f"<<  std::endl : (temp.str().find(".") != std::string::npos) ? std::cout <<"float = " << ptrf <<"f"<< std::endl : std::cout <<"float = " << ptrf <<".0f"<< std::endl;
	temp.flush();
	temp << ptrd;
	(out_of_range) ? std::cout <<"double = " << ptrd <<  std::endl : (temp.str().find(".") != std::string::npos) ? std::cout <<"double = " << ptrd <<std::endl : std::cout <<"double = " << ptrd <<".0" << std::endl;
}