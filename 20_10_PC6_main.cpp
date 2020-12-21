// Header files section
#include "PC6_NumDays.h"
#include "PC6_TimeOff.h"

// start main function
int main()
{  
   const int SICK_HOURS = 8;
   const int VACATION_HOURS = 12;  
   int workMonths;
   string empName;
   string empId;

   //  Get employee info
   cout << "Enter the employee's name: ";
   cin >> empName;
   cout << "Enter ID: ";
   cin >> empId;

   // create an instance of TimeOff class
   TimeOff emp(empName, empId);

   cout << "\nEnter the number of months the employee has worked: ";
   cin >> workMonths;

   emp.setMaxSickDays(workMonths * SICK_HOURS);
   emp.setMaxVacation(workMonths * VACATION_HOURS);

   cout << "\nMaximum number of sick leave earned by " << emp.getEmployeeName() << ": " << emp.getMaxSickDays() << " days" << endl;
   cout << "Maximum number of vacation earned by " << emp.getEmployeeName() << ": " << emp.getMaxVacation() << " days" << endl;
  
   return 0;
} // end of main function
