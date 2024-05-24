#include "AcountHandler.hpp"
AcountHandler::AcountHandler(){
	idx =0;
}
void AcountHandler::add_account(Account *a){
	bank[idx++] = a;
}
void AcountHandler::show_info(){
	for (int i = 0; i < idx; i++)
		bank[i]->show_account();
}