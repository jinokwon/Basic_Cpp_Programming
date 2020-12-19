// NumDays class implementation
#include "PC6_NumDays.h"

// initializes the member variables
NumDays::NumDays(int h)
{
   hours = h;
   days = h / 8.0;
}

// returns the hours in NumDays
int NumDays::getHours() const
{
   return hours;
}

// returns the days in NumDays
double NumDays::getDays() const
{
   return days;
}

// sets the hours in NumDays
void NumDays::setHours(int h)
{
   hours = h;
   days = h / 8.0;
}

// sets the days in NumDays
void NumDays::setDays(double d)
{
   days = d;
   hours = int(d * 8);
}

// overload the addition operator (+)
int NumDays::operator+(const NumDays &right)
{
   return hours + right.hours;
}

// overload the subtraction operator (-)
int NumDays::operator-(const NumDays &right)
{
   if (hours < right.hours)
   {
       cout << "ERROR: Subtraction not possible. Terminating..." << endl;
       exit(0);
   }

   return hours - right.hours;
}

// overload the prefix increment operator (++)
NumDays NumDays::operator++()
{
   ++hours;
   days = hours / 8.0;
   return *this;
}

// overload the postfix increment operator (++)
NumDays NumDays::operator++(int)
{
   NumDays temp(hours);
   hours++;
   days = hours / 8.0;
   return temp;
}

// overload the prefix decrement operator (--)
NumDays NumDays::operator--()
{
   --hours;
   days = hours / 8.0;
   return *this;
}

// overload the postfix decrement operator (--)
NumDays NumDays::operator--(int)
{
   NumDays temp(hours);
   hours--;
   days = hours / 8.0;
   return temp;
}
