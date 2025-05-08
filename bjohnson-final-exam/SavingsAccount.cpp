#include "SavingsAccount.h"
#include <iostream>


SavingsAccount::SavingsAccount(string holder, int accNum, double bal, double interest) :
	BankAccount(holder, accNum, bal), interestRate(interest / 100) {} //convert percent to useble value

void SavingsAccount::applyInterest() { deposit(getBal() * interestRate); }

void SavingsAccount::displayAccountInfo()
{
	BankAccount::displayAccountInfo();
	std::cout << "Account Interestrate: %" << interestRate * 100 << endl;
}
