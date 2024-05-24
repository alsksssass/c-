#include "Account_Credit.hpp"
#include "AcountHandler.hpp"

int main()
{
	AcountHandler a;
	Account* sabyun = new Account("192","sabyun",1000,3);	
	a.add_account(sabyun);
	Account* chansu = new Account_Credit("180","chansu",2000,10,2);
	a.add_account(chansu);
	a.show_info();
}