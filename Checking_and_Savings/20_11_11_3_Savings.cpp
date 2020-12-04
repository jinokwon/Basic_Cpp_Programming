#include <iostream>
#include "Savings.h"
using namespace std;

void Savings::withdraw(double amount)
{
	if (status == false)
	{
		cout << "Account is inactive.\n\n";
		return;
	}
	if (amount < 0)
   		cout << "Withdraw positive numbers only.\n";

	else if (balance - amount < 25.00 && balance - amount > 0)
	{
		cout << "\nYour account has fallen below $25.00.\n";
		cout << "It will be deactivated.\n";
		Account::withdraw(amount);
		status = false;
	}
	
	else if (balance - amount < 0)
	{
   		cout << "You are attempting to withdraw more than the ";
		cout << "account balance.\n";
	}
	else
		Account::withdraw(amount);  // base class function call
}

void Savings::deposit(double amt)
{

	if (balance > 25) status = true;
	Account::deposit(amt);
}

void Savings::monthlyProc()
{
	cout << "\n\nSAVINGS ACCOUNT MONTHLY STATISTICS:";

	if (withdrawals > 4)
	{
		serviceCharges += 1.00f * withdrawals;
	}

	Account::monthlyProc();
	Account::getMonthlyStats();
	deposits = 0;
	withdrawals = 0;
	serviceCharges = 0;
}