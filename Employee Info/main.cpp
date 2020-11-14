// You must use functions, arrays, vectors, structures and classes. 

// Write a C++ to calculate the Payroll for the following set of employees with the menu options: 1. Read employees info from a file with the information below (Set) 2.  Display file information (Get)  3. Process Payroll - Print information to screen and file 4. Exit  Payroll Tax = 22%

// Name      Hours of work  Pay Rate      Bonus   Pay
// Jane Doe  25             40.66         5100
// John Doe  35             27.50         3100
// Jon Doe   22             45.66         6100
// Jenny Doe 37.5           37.50         1800 
// Janet Doe 40             39.50         7100

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const int SIZE = 10;
//'Employee' structure will store each employee's info
struct Employee
{
// using the array to store the names.
   char name[SIZE];
   double workHours;
   double payRate;
   double bonus;
};

// This makes infoType a data type that holds employee info structures.
typedef Employee infoType[50];

// function prototypes
void readInfo(ifstream&, infoType, int&);

// Class to calculate, display, and write to file.
class Calculator
{
private:
    double hrs;
    double pay;
    double bon;
    double gross;
    double net;
    const double TAX = 0.22;
public:
// This class (constructor) takes a vector as input
    Calculator(vector<double> vec)
    {
      hrs = vec.at(0);
      pay = vec.at(1);
      bon = vec.at(2);
    }

    double grossCalc()
    {
      gross = hrs * pay + bon;
      return gross;
    }

    double netCalc()
    {
      net = (hrs * pay + bon) * (1-TAX);
      return net;
    }
};

int main()
{
    ifstream indata;
    ofstream outdata;
    int numOfRecord;
    infoType emp;
    vector<double> record;
    
    indata.open("employee.dat");
    outdata.open("out.dat");
    outdata << left << fixed << setprecision(2);

    int choice;
    do
    {
        cout << "\n =========== M E N U =========== \n";
        cout << "1. Read Employees Info" << endl;
        cout << "2. Display Employee File Info" << endl;
        cout << "3. Process Payroll" << endl;
        cout << "4. Exit Payroll" << endl;
        cout << "Please enter your choice between 1-4: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!indata)
            {
                cout << "Error - can't open the file.\n";
                return 1;
            }
            else
                readInfo(indata, emp, numOfRecord);
                cout << "Read employee info successfully!" << endl;
            break;
        case 2:
            for (int count=0; count < numOfRecord; count++)
            {
                cout << "Employee Name: " << emp[count].name << endl;
                cout << "Work Hours: " << emp[count].workHours << " hours" << endl;
                cout << "Pay Rate: $" << emp[count].payRate << endl;
                cout << "Bonus: $" << emp[count].bonus << endl;
            }
            break;
        case 3:
            //  Print info to screen
            cout << "Name" << setw(15) << "Hours" << setw(10) << "Pay Rate" << setw(10) << "Bonus" << setw(10) << "Gross Pay" << setw(10) << "Net Pay" << endl;

            // Write info to a file.
            outdata << "Name     " << setw(10) << "Hours" << setw(10) << "Pay Rate" << setw(10) << "Bonus" << setw(10) << "Gross Pay" << setw(10) << "Net Pay" << endl;
            
            for (int count=0; count < numOfRecord; count++)
            {
              // vector 'record' holds numerical values needed for calculating pay amount.
                record = {emp[count].workHours, emp[count].payRate, emp[count].bonus};
                Calculator c(record);
                double grossPay = c.grossCalc();
                double netPay = c.netCalc();

                // Print info to screen
                cout << emp[count].name << setw(10) << record.at(0) << setw(10) << record.at(1) << setw(10) << record.at(2) << setw(10) << grossPay << setw(10) << netPay << endl;
                // Write info to a file
                outdata << emp[count].name << setw(10) << record.at(0) << setw(10) << record.at(1) << setw(10) << record.at(2) << setw(10) << grossPay << setw(10) << netPay << endl;
                record.clear();
            }
            break;
        case 4:
            cout << "Exit Payroll Program!" << endl;
            indata.close();
            outdata.close();
            exit(EXIT_SUCCESS);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}

void readInfo(ifstream& inFile, infoType empRec, int& numOfEmp)
{
    numOfEmp = 0;
    inFile.get(empRec[numOfEmp].name, SIZE);

    while (inFile)
    {
        inFile >> empRec[numOfEmp].workHours;
        inFile >> empRec[numOfEmp].payRate;
        inFile >> empRec[numOfEmp].bonus;

        numOfEmp ++;
        inFile.ignore();
        inFile.get(empRec[numOfEmp].name, SIZE);
    }
}