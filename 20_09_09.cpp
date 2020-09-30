// 2020-09-09 class

#include<iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> numbers {10, 20, 30, 40, 50 };

  numbers.push_back(75);
  int howbig = numbers.size();

  for (int val: numbers)
    cout << val << endl;

  cout << "Total elements: " << howbig << endl;
  return 0;
}
// ---------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> number(5);
  int total(0);

  for (int &val : numbers)
  {
    cout << "Enter an integer value: ";
    cin >> val;
  }
  cout << "Here are the values that you entered:\n";
  for (int val : numbers)
  {
    cout << val << endl;
    total += val;
  }
  cout << "Total = " << total << endl;
  cout << "Average = " << total/5 << endl;
  return 0;
}

