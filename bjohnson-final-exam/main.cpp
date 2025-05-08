#include "SavingsAccount.h"
#include <iostream>

using namespace std;


int main()
{
	BankAccount* account = new BankAccount("Billy Bob James", 1832, 2380.08);
	account->deposit(55.03);
	if (!account->withdraw(23.78)) { cout << "error: Insufitiant balance" << endl; }
	cout << "Bank account..." << endl;
	account->displayAccountInfo();
	delete account;
	account = nullptr;
	SavingsAccount* savings = new SavingsAccount("Jamie L. Watson", 2283, 8275.53, 3.2);
	savings->deposit(123.75);
	savings->applyInterest();
	if (!savings->withdraw(23.78)) { cout << "error: Insufitiant balance" << endl; }
	cout << "Savings account..." << endl;
	savings->displayAccountInfo();
	cout << endl << endl;
	delete savings;
	savings = nullptr;
	return 0;
}

