// TimeOff class declaration
#ifndef PC6_TIMEOFF_H
#define PC6_TIMEOFF_H
#include "PC6_NumDays.h"

class TimeOff
{
private:
   // member variables
   string employeeName;
   string employeeID;  
   NumDays maxSickDays;
   NumDays sickTaken;
   NumDays maxVacation;
   NumDays vacTaken;
   NumDays maxUnpaid;
   NumDays unpaidTaken;

public:
   TimeOff(string en = "", string eid = "");
   string getEmployeeName() const;
   string getEmployeeID() const;
   double getMaxSickDays() const;
   double getSickTaken() const;
   double getMaxVacation() const;
   double getVacTaken() const;
   double getMaxUnpaid() const;
   double getUnpaidTaken() const;
   void setEmployeeName(string en);
   void setEmployeeID(string eid);
   void setMaxSickDays(int h);
   void setSickTaken(int h);
   void setMaxVacation(int h);
   void setVacTaken(int h);
   void setMaxUnpaid(int h);
   void setUnpaidTaken(int h);
};
#endif // TIMEOFF_H
