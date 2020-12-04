#include <iostream>
#include "Checking.h"
#include "Account.h"
using namespace std;

void Checking::withdraw(double amt)
{
	if (status == false)
	{
		cout << "Account is inactive.\n\n";
		return;
	}
	if (amt < 0)
   		cout << "Withdraw positive numbers only.\n";

	else if (balance - amt < 25 && balance - amt > 0)
	{
		cout << "\nYour account has fallen below $25.00.\n";
		cout << "It will be deactivated.\n";
		status = false;
	}
	
	else if (balance - amt < 0)
	{
   		cout << "You are attempting to withdraw more than the ";
		serviceCharges += 15.00;
		cout << "account balance.\n";
	}
	else
		Account::withdraw(amt);  // base class function call
}

void Checking::deposit(double amount)
{
	if (status == false)
	{
		cout << "Account is inactive.\n\n";
		return;
	}
	Account::deposit(amount);	
}

void Checking::monthlyProc()
{
	cout << "\n\nCHECKING ACCOUNT MONTHLY STATISTICS:";
	serviceCharges += (5.00f + (withdrawals * .10f));  // first 4 are free
	Account::monthlyProc();
	Account::getMonthlyStats();
	deposits = 0;
	withdrawals = 0;
	serviceCharges = 0; 
}