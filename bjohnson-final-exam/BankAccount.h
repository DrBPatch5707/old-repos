#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>


using namespace std;
class BankAccount
{
 public:
	 BankAccount(string holder, int accNum, double bal);

	 void deposit(double amt);

	 bool withdraw(double amt);

	 void displayAccountInfo();

	 double getBal();


 private:
	 string accountHolder;
	 int accountNumber;
	 double balance;
};
#endif // !BANKACCOUNT_H
