#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
	double balance;
	int deposits;
	int withdrawals;
	double interestRate;
	double serviceCharges;
	bool status;
public:
	Account();
	virtual void deposit(double);
	virtual void withdraw(double);
	virtual void calcInt();
	virtual void monthlyProc();
	void getMonthlyStats();

};

#endif