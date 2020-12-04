#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;

Account::Account()
{
	balance = 0.00;
	interestRate = 0.05;  // annual interest
	status = true;	      // active = true, inactive = false
	withdrawals = 0;
	deposits = 0;
	serviceCharges = 0.00;
}

void Account::deposit(double amount)
{
	balance += amount;
	deposits++;
}

void Account::withdraw(double amount)
{
	balance -= amount;
	withdrawals++;
}

void Account::calcInt()  // updates Balance
{
	double monthlyInterestRate = interestRate / 12;
	double monthlyInterest = balance * monthlyInterestRate;
	balance += monthlyInterest;
}

void Account::monthlyProc()
{
	calcInt();   // calculate the interest
	balance -= serviceCharges;
}

void Account::getMonthlyStats()
{
	cout << "\nWithdrawals:\t\t" << withdrawals;
	cout << "\nDeposits:\t\t" << deposits;
	cout << setprecision(2);
	cout << fixed << showpoint;
	cout << "\nService Charges:\t" << serviceCharges;
	cout << "\n\nEnding Balance:\t\t" << balance << endl << endl;
}