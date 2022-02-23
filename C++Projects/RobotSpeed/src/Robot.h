#ifndef ROBOT_H
#define ROBOT_H

class Robot
{

private:

	double gearSpeed, //the gear motor speed in revolutions per minute
		wheelDiameter; //the wheel diameter in inches

public:

	Robot();
	void setRPM(double newRPM);
	void setDiameter(double newDiameter);
	double getRPM();
	double getDiameter();
	double getSpeed();


};
#endif
