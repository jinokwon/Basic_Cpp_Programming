// Specification file for the PreferredCustomer class
#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H
#include "CustomerData.h"

class PreferredCustomer : public CustomerData
{
private:
	double purchasesAmount;		// Holds the amount of a customer's purchases
	double discountLevel;		// Holds the customer's discount level
	void determineDiscountLevel();	// Determines the discount level

public:
	// Default Constructor
	PreferredCustomer() : CustomerData()
		{ purchasesAmount = 0; discountLevel = 0; }
	
	// Constructor
	PreferredCustomer(string ln, string fn, string addr,
                string c, string s, string z, string ph,
				int cn, bool ml, double pa, double dl) : 
	CustomerData(ln, fn, addr, c, s, z, ph, cn, ml)
		{ purchasesAmount = pa; discountLevel = dl; }

	// Mutator
	void setPurchasesAmount(double p)
		{ purchasesAmount = p; 
		  determineDiscountLevel(); }

	// Get functions
	double getPurchasesAmount()
		{ return purchasesAmount; }

	double getDiscountLevel()
		{ determineDiscountLevel();
	      return discountLevel; }

	// Function to add an amount to the purchases amount
	void addPurchase(double p)
		{ purchasesAmount += p; }
};

#endif