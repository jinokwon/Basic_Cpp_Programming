// 2020-09-14 'swap'

#include <iostream>
using namespace std; //swap using pointer
void swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

int main()
{
    int n1 = 0, n2 = 0;
    cout<<"Please enter n1: ";
    cin>>n1;
    cout<<"and n2: ";
    cin>>n2;
    cout<<"Before swapping, n1="<<n1<<" and n2="<<n2<<"\n";
    swap(&n1, &n2);
    cout<<"After swapping, n1="<<n1<<" and n2="<<n2<<"";
    return 0;
}

// ------------------------------------
// Ex. 9-14

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double *sales = nullptr, total=0.0, average;
    int numDays, count;

    cout << "How many days of sales amounts do you wish to process? ";
    cin >> numDays;

    sales = new double[numDays];
    cout << "Enter the sales amounts below.\n";
    for (count = 0; count << numDays; count++)
    {
        cout << "Day " << (count+1) << ": ";
        cin >> sales[count];
    }

    for (count=0; count < numDays; count++)
    {
        total += sales[count]
    }

    average = total / numDays;
    cout << fixed << showpoint << setprecision(2);
    cout << "\n\nTotal Sales: $" << total << endl;
    cout << "Average Sales: $" << average << endl;

    delete[] sales;
    sales =  nullptr;

    return 0;
}
// ------------------------------------------------------------
