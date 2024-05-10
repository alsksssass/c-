#include <string>
#ifndef HARL_H
#define HARL_H
class Harl{
	private:
		static void debug(void);
		static void info(void);
		static void warning(void);
		static void error(void);
	public:
		static void complain(std::string level);
};

#endif