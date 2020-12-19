// TimeOff class implementation
#include "PC6_TimeOff.h"

// initializes the member variables
TimeOff::TimeOff(string en, string eid)
{
   employeeName = en;
   employeeID = eid;
}

// returns the employee name
string TimeOff::getEmployeeName() const
{
   return employeeName;
}

// returns the employee ID
string TimeOff::getEmployeeID() const
{
   return employeeID;
}

// returns the maximum number of days sick leave the employee can take
double TimeOff::getMaxSickDays() const
{
   return maxSickDays.getDays();
}

// returns the number of days sick leave the employee already has taken
double TimeOff::getSickTaken() const
{
   return sickTaken.getDays();
}

// returns the maximum number of days paid vaction the employee can take
double TimeOff::getMaxVacation() const
{
   return maxVacation.getDays();
}

// returns the number of days paid vaction the employee already has taken
double TimeOff::getVacTaken() const
{
   return vacTaken.getDays();
}

// returns the maximum number of days unpaid vaction the employee can take
double TimeOff::getMaxUnpaid() const
{
   return maxUnpaid.getDays();
}

// returns the number of days unpaid vaction the employee already has taken
double TimeOff::getUnpaidTaken() const
{
   return unpaidTaken.getDays();
}

// sets the name of the employee
void TimeOff::setEmployeeName(string en)
{
   employeeName = en;
}

// sets the ID of the employee
void TimeOff::setEmployeeID(string eid)
{
   employeeID = eid;
}

// sets the maximum number of days sick leave the employee can take
void TimeOff::setMaxSickDays(int h)
{
   maxSickDays.setHours(h);
}

// sets the number of days sick leave the employee already has taken
void TimeOff::setSickTaken(int h)
{
   sickTaken.setHours(h);
}

// sets the maximum number of days paid vaction the employee can take
void TimeOff::setMaxVacation(int h)
{
   if (h > 240)
       maxVacation.setHours(240);
   else
       maxVacation.setHours(h);
}

// sets the number of days paid vaction the employee already has taken
void TimeOff::setVacTaken(int h)
{
   vacTaken.setHours(h);
}

// sets the maximum number of days unpaid vaction the employee can take
void TimeOff::setMaxUnpaid(int h)
{
   maxUnpaid.setHours(h);
}

// sets the number of days unpaid vaction the employee already has taken
void TimeOff::setUnpaidTaken(int h)
{
   unpaidTaken.setHours(h);
}
