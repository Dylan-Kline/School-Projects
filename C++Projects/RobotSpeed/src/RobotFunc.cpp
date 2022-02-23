#include "Robot.h"

//Initializes the gear motor speed and wheel diameter
Robot::Robot()
{
	gearSpeed = 74;
	wheelDiameter = 1;
}

//Validates User inputted newRPM, if valid it is stored in gearSpeed, else the function does nothing
void Robot::setRPM(double newRPM)
{
	if (newRPM == 74 || newRPM == 190 || newRPM == 265)
	{
		gearSpeed = newRPM;
	}
	
}

//Validates User inputted newDiameter, if valid it then stores the value in wheelDiameter, else does nothing
void Robot::setDiameter(double newDiameter)
{
	if (newDiameter >= 1 && newDiameter <= 6)
	{
		wheelDiameter = newDiameter;
	}
}

//Returns the value of gearSpeed when called
double Robot::getRPM()
{
	return gearSpeed;
}

//Returns the value of wheelDiameter
double Robot::getDiameter()
{
	return wheelDiameter;
}

//Returns the robots speed in feet per minute
double Robot::getSpeed()
{
	return((gearSpeed * wheelDiameter * 3.14159) / 12);
}
