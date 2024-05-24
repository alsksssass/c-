#include "Account.hpp"
#include <iostream>
using namespace std;
Account::Account()
{
	this->NAME = "";
	this->ID = "";
	this->account_amount = 0;
	this->income = 0;
}
Account::Account(std::string ID, std::string NAME, int money, int income)
{
	this->NAME = NAME;
	this->ID = ID;
	this->account_amount = money;
	this->income = income;
}
int Account::get_amount()
{
	return account_amount;
}
int Account::get_income()
{
	return income;
}
void Account::withdraw(int amount)
{
	if (account_amount - amount > 0)
	{
		account_amount -= amount;
	}
}
void Account::add_money(int amount)
{
	if (amount < 0)
		return;
	account_amount += amount;
}
std::string Account::get_name(){
	return NAME;
}
std::string Account::get_id(){
	return ID;
}
void Account::show_account()
{
	cout << " 계좌 ID : " << get_id() << '\n' << "이름 : " << get_name() <<'\n' << "입금액 : " << get_amount() << '\n' << "이자율 : " << get_income() << endl;
}