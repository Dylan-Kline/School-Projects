#include "Employee.h"

//Constructor
Employee::Employee(int initId, const char initName[],
    double initHourlyPay,
    int initNumDeps, int initType)
{
    bool status = set(initId, initName, initHourlyPay,
        initNumDeps, initType);

    if (!status)
    {
        id = 0;

        for (int i = 0; i <= 20; i++)
        {
            name[i] = ' ';
        }

        hourlyPay = 0.0;
        numDeps = 0;
        type = 0;
    }
}

//Sets employee info
bool Employee::set(int newId, const char* newName, double newHourlyPay,
    int newNumDeps, int newType)
{
    bool status = false;

    if (newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 &&
        newType >= 0 && newType <= 1)
    {
        status = true;
        id = newId;
        strcpy_s(name, newName);
        hourlyPay = newHourlyPay;
        numDeps = newNumDeps;
        type = newType;
    }
    return status;
}

int Employee::searchID(Employee array[], int ID)
{
    bool found = false;
    int pos = -1,
        index = 0;

    while (index < 100 && found == false)
    {
        if (array[index].getID() == ID)
        {
            found = true;
            pos = index;
        }
        index++;
    }

    return pos;
}

//gets employee's ID
int Employee::getID()
{
    return id;
}

//gets employee's name
char* Employee::getName()
{
    return name;
}

//gets employee's pay rate
double Employee::getHourlyPay()
{
    return hourlyPay;
}

//gets the number of dependents for an employee
int Employee::getNumDeps()
{
    return numDeps;
}

//gets the employee's type
int Employee::getType()
{
    return type;
}
