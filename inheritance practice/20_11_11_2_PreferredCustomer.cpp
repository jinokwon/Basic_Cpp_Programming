// Implementation file for the PreferredCustomer class
#include "PreferredCustomer.h"

//******************************************
// determineDiscountLevel member function  *
//******************************************

void PreferredCustomer::determineDiscountLevel()
{
	if (purchasesAmount >= 2000)
		discountLevel = 0.10;
	else if (purchasesAmount >= 1500)
		discountLevel = 0.07;
	else if (purchasesAmount >= 1000)
		discountLevel = 0.06;
	else if (purchasesAmount >= 500)
		discountLevel = 0.05;
}