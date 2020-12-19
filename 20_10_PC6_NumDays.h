// NumDays class declaration
#ifndef PC6_NUMDAYS_H
#define PC6_NUMDAYS_H
#include <iostream>
#include <string>
using namespace std;

class NumDays
{
private:
   int hours;
   double days;

public:
   NumDays(int h = 0);

   // getter functions
   int getHours() const;
   double getDays() const;

   // setter functions
   void setHours(int h);
   void setDays(double d);

   // addition and subtraction operators
   int operator+(const NumDays &right);
   int operator-(const NumDays &right);

   // prefix and postfix increment operators
   NumDays operator++();
   NumDays operator++(int);

   // prefix and postfix decrement operators
   NumDays operator--();
   NumDays operator--(int);
};
#endif
