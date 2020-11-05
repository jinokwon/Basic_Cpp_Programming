// Chapter 12, Programming Challenge 12: Corporate Sales Data Input
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

// Constant for array size
const int SIZE = 12;

// Declaration of the Division structure
struct Division
{
   char divName[SIZE];  // Division name
   int quarter;         // Quarter number
   double sales;        // Quarterly sales
};

// Function prototypes
void findHighandLow(double, double, double, double,
                    double &, double &);
void displayResults(double, double, double, double,
                    double, double, double, double,
                    double, double, double);

int main()
{
   // File stream object for the corp.dat file
   fstream file("corp.dat", ios::in | ios::binary);
   
   // Division structure variable
   Division corp;
   
   // Variables to hold quarterly total sales
   double totalQ1 = 0,   // 1st quarter
          totalQ2 = 0,   // 2nd quarter
          totalQ3 = 0,   // 3rd quarter
          totalQ4 = 0;   // 4th quarter
          
   // Variables to hold annual sales totals
   double eastYear = 0,  // East division
          westYear = 0,  // West division
          northYear = 0, // North division
          southYear = 0; // South division
          
   // Variables to hold total sales, highest quarter,
   // and lowest quarter.
   double totalCorp = 0, 
          highest, 
          lowest;

   // Read data for a division.
   file.read(reinterpret_cast<char *>(&corp), sizeof(corp));

   // Read the data from the file and process it.
   while(!file.eof())
   {
      // In case of error, terminate.
      if (file.fail())
      {
         cout << "Error reading file.\n";
         exit(EXIT_FAILURE);
      }
      
      // Keep a running total of all sales.
      totalCorp += corp.sales;
      
      // Accumulate the divisional sales data.
      if (strcmp(corp.divName, "East") == 0)
         eastYear += corp.sales;
      else if (strcmp(corp.divName, "West") == 0)
         westYear += corp.sales;
      else if (strcmp(corp.divName, "North") == 0)
         northYear += corp.sales;
      else if (strcmp(corp.divName, "South") == 0)
         southYear += corp.sales;
         
      // Accumulate the quarterly sales data.
      if (corp.quarter == 1)
         totalQ1 += corp.sales;
      else if (corp.quarter == 2)
         totalQ2 += corp.sales;
      else if (corp.quarter == 3)
         totalQ3 += corp.sales;
      else if (corp.quarter == 4)
         totalQ4 += corp.sales;
      
      // Read data for a division.
      file.read(reinterpret_cast<char *>(&corp), sizeof(corp));
   }
   
   // Close the file.
   file.close();
   
   // Find the highest and lowest quarters.
   findHighandLow(totalQ1, totalQ2, totalQ3, totalQ4, highest, lowest);
   
   // Display the results.
   displayResults(totalQ1, totalQ2, totalQ3, totalQ4,
                  eastYear, westYear, northYear, southYear,
                  totalCorp, highest, lowest);
   return 0;
}

//**************************************************
// Function findHighand Low                        *
// This function finds the highest and lowest      *
// quarterly sales.                                *
//**************************************************
void findHighandLow(double totalQ1, double totalQ2, 
                    double totalQ3, double totalQ4,
                    double &highest, double &lowest)
{
   // Find highest quarterly sales
   highest = lowest = totalQ1;
   if (totalQ2 > highest)
      highest = totalQ2;
   if (totalQ3 > highest)
      highest = totalQ3;
   if (totalQ4 > highest)
      highest = totalQ4;
      
   // Find lowest quarterly sales
   if (totalQ2 < lowest)
      lowest = totalQ2;
   if (totalQ3 < lowest)
      lowest = totalQ3;
   if (totalQ4 < lowest)
      lowest = totalQ4;
}

//*************************************************************
// Function displayResults                                    *
// This function displays the financial report.               *
//*************************************************************
void displayResults(double totalQ1, double totalQ2, 
                    double totalQ3, double totalQ4,
                    double eastYear, double westYear,
                    double northYear, double southYear,
                    double totalCorp, double highest,
                    double lowest)
{
   cout << setprecision(2) << fixed << showpoint;
   
   // Total corporate quarterly sales
   cout << "Corporate sales for 1st quarter: $" << totalQ1 << endl;
   cout << "Corporate sales for 2nd quarter: $" << totalQ2 << endl;
   cout << "Corporate sales for 3rd quarter: $" << totalQ3 << endl;
   cout << "Corporate sales for 4th quarter: $" << totalQ4 << endl;
   
   // Total yearly sales for each division
   cout << "Total yearly sales for each division:\n";
   cout << "\tEast: $" << eastYear << endl;
   cout << "\tWest: $" << westYear << endl;
   cout << "\tNorth: $" << northYear << endl;
   cout << "\tSouth: $" << southYear << endl;
   
   // Total yearly corporate sales
   cout << "Total yearly corporate sales: $" << totalCorp << endl;
   
   // Average quarterly sales for each division
   cout << "Average quarterly sales for each division:\n";
   cout << "\tEast: $" << (eastYear/4) << endl;
   cout << "\tWest: $" << (westYear/4) << endl;
   cout << "\tNorth: $" << (northYear/4) << endl;
   cout << "\tSouth: $" << (southYear/4) << endl;
   
   // Highest and Lowest quarters:
   cout << "Highest quarterly sales: $" << highest << endl;
   cout << "Lowest quarterly sales: $" << lowest << endl;
}