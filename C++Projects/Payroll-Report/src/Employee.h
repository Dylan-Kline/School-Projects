#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>


class Employee
{
private:
    int id;             // employee ID
    char name[21];        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type

public:
    Employee(int initId = 0, const char initName[] = "",
        double initHourlyPay = 0.0,
        int initNumDeps = 0, int initType = 0);  // Constructor

    bool set(int newId, const char* newName, double newHourlyPay,
        int newNumDeps, int newType);

    int searchID(Employee array[], int ID);
    int getID();
    char* getName();
    double getHourlyPay();
    int getNumDeps();
    int getType();

};

#endif 
