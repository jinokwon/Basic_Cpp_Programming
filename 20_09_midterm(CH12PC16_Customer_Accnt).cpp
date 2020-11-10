// Chapter 12, Programming Challenge 16: Customer Accounts

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Constant for array sizes
const int SIZE = 45;

fstream custFile;      // Customer file
fstream tempFile;      // For deletion swap

struct Customer
{
   char name[SIZE];
   char address[SIZE];
   char city[SIZE];
   char state[SIZE];
   char zip[SIZE];
   char phone[SIZE];
   double balance;
   char lastPay[SIZE];
};

// Function prototypes
void setInfo(long);     // write record to file
void display(long);     // display one record
long search();          // find a record & return file position
void deleteRec(long);   // delete one record
void showAll();         // display all records

// flags to signal setInfo()
bool rnew = false;      // To signal if the record is new  
bool mod = false;       // To signal if the record is being modified

int main()
{
   long fpos;       // The file position
   int choice = 6;	// The user's choice
   char yesOrNo;	// To hold 'y' or 'n'

   // Display the menu until the user exits the program.
   do
   {
      cout << "\n * * * * M A I N   M E N U * * * * * * * \n\n";
      cout << "1. Enter a new Customer Account\n";
      cout << "2. Display a Customer Account\n";
      cout << "3. Delete a Customer Account\n";
      cout << "4. Change a Customer Account\n";
      cout << "5. Display All Customer Accounts\n";
      cout << "6. Exit the program\n\n";
      
      cout << "Enter your choice (1-6): ";
      cin >> choice;
      while (choice < 1 || choice > 6)
      {
         cout << "Enter 1 - 6 please: ";
         cin >> choice;
      }
      
	  // Determine the user's choice.
      switch (choice)
      {
      case 1:  
         cin.get();
         cout << "\nYou selected Enter a new Customer Account.\n\n";
         rnew = true;
         setInfo(0);  
         rnew = false;
         break;
         
      case 2: 
         cout << "\nYou selected Display a Customer Account.\n\n";
         fpos = search();
         if (fpos != -1)
         {
            display(fpos); 
         }
         else
            cout << "\nRecord not found.";
         break;
         
      case 3: 
         cout << "\nYou selected Delete a Customer Account.\n\n";
         fpos = search();
         if (fpos != -1)
         {
            display(fpos);
            cout << "\nARE YOU SURE YOU WANT TO DELETE THIS RECORD? (Y/N) ";
            cin >> yesOrNo;
            yesOrNo = toupper(yesOrNo);
            if (yesOrNo == 'Y')
            {
               deleteRec(fpos);
               break;
            }
            else
            {
               cout << "\nRecord was not deleted.\n";
               break;
            }
         }
         else
            cout << "\nRecord not found.\n";
         break;
         
      case 4: 
         cout << "\nYou selected Change a Customer Account.\n\n";
         fpos = search();
         mod = true;
         if (fpos != -1)
         {  
            cout << "\nRECORD CONTENTS: \n";
            display(fpos);
            cout << "\nENTER NEW CONTENTS: \n";
            setInfo(fpos);
            mod = false;
         }
         else
            cout << "\nRecord not found.\n";
         break;
         
      case 5: 
         cout << "\nYou selected Display All Customer Account.\n\n";
         showAll();
         break;
         
      case 6:
         exit(EXIT_SUCCESS);
         break;
         
      default:  // anything not between 1-6
         break;
      } //end switch

   } while (choice != 6);

   return 0;
}

// *****************************************************************
// The setInfo function write record to the file.                  *
// *****************************************************************
void setInfo(long fp)  
{
   Customer c;

   cout << "\nPlease enter the following information:\n";
   cout << "\nCustomer name: ";
   cin.getline(c.name, SIZE);
   while (strlen(c.name) == 0)
   {
      cout << "You must enter a name: ";
      cin.getline(c.name, SIZE);
   }

   cout << "Customer address: ";
   cin.getline(c.address, SIZE);
   while (strlen(c.address) == 0)
   {
      cout << "You must enter an address: ";
      cin.getline(c.address, SIZE);
   }
   
   cout << "City: ";
   cin.getline(c.city, SIZE);
   while (strlen(c.city) == 0)
   {
      cout << "You must enter a city: ";
      cin.getline(c.city, SIZE);
   }
   
   cout << "State: ";
   cin.getline(c.state, SIZE);
   while (strlen(c.state) == 0)
   {
      cout << "You must enter a state: ";
      cin.getline(c.state, SIZE);
   }

   cout << "ZIP: ";
   cin.getline(c.zip, SIZE);
   while (strlen(c.zip) == 0)
   {
      cout << "You must enter a ZIP code: ";
      cin.getline(c.zip, SIZE);
   }

   cout << "Telephone: ";
   cin.getline(c.phone, SIZE);
   while (strlen(c.phone) == 0)
   {
      cout << "You must enter a telephone number: ";
      cin.getline(c.phone, SIZE);
   }

   cout << "Account balance: ";
   cin >> c.balance;
   while (c.balance < 0)
   {
      cout << "Please enter 0 or geater for account balance: ";
      cin >> c.balance;
   }

   cin.get();
   cout << "Date of last payment: ";
   cin.getline(c.lastPay, SIZE);
   while (strlen(c.lastPay) == 0)
   {
      cout << "You must enter the date of the last payment: ";
      cin.getline(c.lastPay, SIZE);
   }

    if (rnew)
    {
        custFile.open("cust.dat", ios::out | ios::app | ios::binary );
    }
    else if (mod)
    {
       custFile.open("cust.dat", ios::in | ios::out | ios::binary);
       custFile.seekp(fp, ios::beg);
    }

    if (custFile.fail())
    {
        cout << "\nError opening file.\n";
        exit(0);
    }
   
    custFile.write(reinterpret_cast<char *>(&c), sizeof(c));
    if (custFile.fail())
    {
        cout << "\nError writing record to file.\n";
		exit(0);
    }
    else
    {
        cout << "\nRecord written to file.\n\n";
        cout << "\nPress Enter to continue...";
        cin.get();
    }

   custFile.close();

} 
// *****************************************************************
// The display function displays a single record.                  *
// *****************************************************************
void display(long fp)
{
   Customer c;

   custFile.open("cust.dat", ios::in | ios::binary);
   if (custFile.fail())
   {
      cout << "\nError opening file.\n";
	  exit(0);
   }
   if (!custFile)
   {
      cout << "\nFile is empty.\n";
      custFile.close();
      exit(0);
   }

   custFile.seekg(fp, ios::beg);
   custFile.read(reinterpret_cast<char *>(&c), sizeof(Customer));
   
   cout << fixed << showpoint << setprecision(2);
   cout << "Customer name: " << c.name << endl;
   cout << "Customer address: " << c.address << endl;
   cout << "City: " << c.city << endl;
   cout << "State: " << c.state << endl;
   cout << "Zip: " << c.zip << endl;
   cout << "Telephone: " << c.phone << endl;
   cout << "Account balance: $" << c.balance << endl;
   cout << "Date of last payment: " << c.lastPay << endl;

   custFile.close();
   cout << "\nPress Enter to continue.";
   cin.get();
}

// *****************************************************************
// The search function returns the file pointer position.          *
// *****************************************************************
long search()
{
   char name[SIZE];
   Customer c;
   long fp;
   cout << "\nEnter all or part of the customer name: ";
   cin.ignore();
   cin.getline(name, SIZE);

   if (name[0] == '\0') // if nothing is entered, do nothing
   {
      return -1;
   }

   custFile.open("cust.dat", ios::in | ios::binary);
   if (custFile.fail())
   {
      cout << "\nError opening file.\n";
      custFile.close();
	  exit(0);
   }

   while (!custFile.eof())
   {
	   // read one record
      custFile.read(reinterpret_cast<char *>(&c), sizeof(Customer));  

	  // Determine if search value matches customer name.
      if (strstr(c.name, name) != nullptr) 
      {
         fp = static_cast<long>(custFile.tellg());
         custFile.close();
         return (fp - sizeof(c));
      }
   }

   cout << "Record not found\n";
   custFile.close();

   return -1;
}

// *****************************************************************
// The showAll function shows all the customer records.            *
// *****************************************************************
void showAll()
{  
   cin.ignore();
   Customer c;
   int count = 0;
   custFile.open("cust.dat", ios::in | ios::binary);
   if (custFile.fail())
   {
      cout << "\nError opening file.\n";
      custFile.close();
	  exit(0);
   }
   cout << "\n***Begin Customer Record Listing***\n\n";

   custFile.read(reinterpret_cast<char *>(&c), sizeof(Customer));
   while (custFile)
   {
      cout << fixed  << showpoint << setprecision(2);
      cout << "\nRECORD NUMBER " << ++count << ":" << endl;
      cout << "\nCustomer name: " << c.name << endl;
      cout << "Customer Address: " << c.address << endl;
      cout << "City: " << c.city << endl;
      cout << "State: " << c.state << endl;
      cout << "Zip: " << c.zip << endl;
      cout << "Telephone: " << c.phone << endl;
      cout << "Account Balance: $" << c.balance << endl;
      cout << "Date of Last Payment: " << c.lastPay << endl;
      cout << endl;
      cout << "\nPress Enter to Continue...";
      cin.get();
      custFile.read(reinterpret_cast<char *>(&c), sizeof(Customer));
   }
   if (count == 0)
   {
      cout << "\nFile is empty." << endl;
   }
   cout << "\n***End of Customer Record Listing***\n\n";
   custFile.close();

}

// *****************************************************************
// This function marks a record for deletion by placing            *
// the null terminator at the beginning of the name member.        *
// The contents of the file are then copied to a temporary file,   *
// then the temporary file is copied back to the Customer file     *
// -- without the deleted record.                                  *
// Ideally, this function would be expanded to allow multiple      *
// record deletions before the final file swap takes place.        *
// *****************************************************************
void deleteRec(long fp)
{
   Customer c;
   int Rec = 0;
   custFile.open("cust.dat", ios::in | ios::out | ios::binary);
   if (custFile.fail())
   {
      cout << "\nError opening file.\n";
      custFile.close();
	  exit(0);
   }

   strcpy(c.name, "\0");  // indicates deletion of record
   custFile.seekp(fp, ios::beg);
   custFile.write(reinterpret_cast<char *>(&c), sizeof(c));
   custFile.close();
   custFile.open("cust.dat", ios::in | ios::binary);
   tempFile.open("temp.dat", ios::out | ios::binary);
   
   custFile.read(reinterpret_cast<char *>(&c), sizeof(c));
   while (custFile)
   {
      tempFile.write(reinterpret_cast<char *>(&c),sizeof(c));
      custFile.read(reinterpret_cast<char *>(&c), sizeof(c));
   }

   custFile.close();
   tempFile.close();

   tempFile.open("temp.dat", ios::in | ios::binary);
   custFile.open("cust.dat", ios::out | ios::binary);

   tempFile.read(reinterpret_cast<char *>(&c), sizeof(c));
   while (!tempFile.eof())
   {
      if (c.name[0] != '\0')
      {
         custFile.write(reinterpret_cast<char *>(&c), sizeof(c));
      }
      tempFile.read(reinterpret_cast<char *>(&c), sizeof(c));
   }

   tempFile.close();
   custFile.close();
   cout << "\nDeletion successful.\n";
}