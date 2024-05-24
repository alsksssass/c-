#ifndef ACOUNT_H
#define ACOUNT_H
class Account {
	private: 
		std::string ID;
		std::string NAME;
		int account_amount;
		int income;
	public:
		Account();
		Account(std::string ID, std::string NAME, int money, int income);
		int get_amount();
		int get_income();
		std::string get_name();
		std::string get_id();
		void withdraw(int amount);
		void add_money(int amount);
		virtual void show_account();
};
#endif