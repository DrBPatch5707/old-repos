#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
 public:
	 SavingsAccount(string holder, int accNum, double bal, double interest);

	 void applyInterest();

	 void displayAccountInfo();

 private:
	 double interestRate;

};

#endif // !SAVINGSACCOUNT_H
