#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
int main(int argc, char **argv)
{
	if(argc != 4)
		return 0;
	std::string get;
	std::string file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream ofile(argv[1]);
	if(ofile.fail() || s1.empty())
		return 0;
	std::string o_name = file_name + ".replace";
	std::ofstream wfile(o_name.c_str());
	if(ofile.fail())
		return 0;
	std::stringstream buffer;
    buffer << ofile.rdbuf();
	get = buffer.str();
	int trum = 0;
	while(1)
	{
		int a = get.find(s1, trum);
		if (a < 0)
			break;
		get.erase(a, s1.size());
		get.insert(a, s2);
		trum = a + s1.size() + 1;
	}
	buffer.str(get);
	wfile << buffer.str() ;
}