// Chapter 15, Programming Challenge 8: PreferredCustomer Class
#include <iostream>
#include <iomanip>
#include "PreferredCustomer.h"
using namespace std;

int main()
{
	// Create a PreferredCustomer object.
	PreferredCustomer customer;

	// Variable to hold the amount of purchases.
	double purchase;

	// Set the customer information in the
	// PreferredCustomer object.
	customer.setLastName("Smith");
	customer.setFirstName("Herman");
	customer.setAddress("487 Main Street");
	customer.setCity("Mayberry");
	customer.setState("NC");
	customer.setZip("55555");
	customer.setPhone("555-5555");
	customer.setCustomerNumber(147);
	customer.setMailingList(true);
	customer.setPurchasesAmount(550.0);

	// Display the basic customer information.
	cout << fixed << showpoint << setprecision(2);
	cout << "Initial Customer Data\n";
	cout << "---------------------\n";
	cout << "Last name: " 
		 << customer.getLastName() << endl;
	cout << "First name: " 
		 << customer.getFirstName() << endl;
	cout << "Address: " 
		 << customer.getAddress() << endl;
	cout << "City: " 
		 << customer.getCity() << endl;
	cout << "State: " 
		 << customer.getState() << endl;
	cout << "ZIP: " 
		 << customer.getZip() << endl;
	cout << "Phone: " 
		 << customer.getPhone() << endl;
	cout << "Customer number: " 
		 << customer.getCustomerNumber() 
		 << endl;

	// Display the mailing list status.
	if (customer.getMailingList())
		cout << "Mailing list: Yes\n";
	else
		cout << "Mailing list: No\n";

	// Display the amount of purchases.
	cout << "Purchases amount: $" 
		 << customer.getPurchasesAmount() 
		 << endl;

	// Display the discount level.
	cout << "Current discount level: " 
		 << customer.getDiscountLevel() 
		 << endl << endl;

	// Add another purchase.
	cout << "Enter an additional purchase amount: ";
	cin >> purchase;
	customer.addPurchase(purchase);

	// Display the amount of purchases now.
	cout << "Purchases amount: $" 
		 << customer.getPurchasesAmount() 
		 << endl;

	// Display the discount level now.
	cout << "Current discount level: " 
		 << customer.getDiscountLevel() 
		 << endl << endl;

	return 0;
}