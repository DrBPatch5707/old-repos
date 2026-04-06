#include "BankAccount.h"
#include <iostream>

using namespace std;


BankAccount::BankAccount(string holder, int accNum, double bal) : 
	accountHolder(holder), accountNumber(accNum), balance(bal) {}

void BankAccount::deposit(double amt) { balance += amt; }

bool BankAccount::withdraw(double amt)
{
	if (amt > balance) { return false; }
	balance -= amt;
	return true;
}

void BankAccount::displayAccountInfo()
{
	cout << "Account Holder: " << accountHolder << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: " << balance << endl;
}

double BankAccount::getBal() { return balance; }


