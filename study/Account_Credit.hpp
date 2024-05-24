#ifndef ACOUNT_CREDIT_H
#define ACOUNT_CREDIT_H
#include "Account.hpp"

class Account_Credit : public Account {
	private:
		int CREDIT;
	public:
		Account_Credit();
		Account_Credit(std::string ID, std::string NAME, int money, int income, int credit);
		int get_credit();
		virtual void show_account();
	
};

#endif