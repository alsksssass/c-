#ifndef ACOUNTHANDLER_H
#define ACOUNTHANDLER_H
#include "Account.hpp" 
class AcountHandler {
	private:
		Account *bank[100];
		int idx;
	public:
		AcountHandler();
		void add_account(Account *a);
		void show_info();
};

#endif