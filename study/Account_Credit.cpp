#include "Account_Credit.hpp"
#include <iostream>
using namespace std;
Account_Credit::Account_Credit() : Account(){
	CREDIT = 0;
}
Account_Credit::Account_Credit(std::string ID, std::string NAME, int money, int income, int credit) : Account(ID,NAME,money,income)
{
	this->CREDIT = credit;
}
int Account_Credit::get_credit(){
	return CREDIT;
}
void Account_Credit::show_account()
{
	Account::show_account();
	cout << "신용등급 : " << get_credit() << endl;
}