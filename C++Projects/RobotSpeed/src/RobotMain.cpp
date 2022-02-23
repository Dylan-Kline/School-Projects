#include "Robot.h"
#include <iostream>


using namespace std;

int main()
{
	Robot robot; //Declares a Robot object

	double newRPM, //Used to store user inputted speeds
		newDiameter; //Stores the user inputted wheel diameter

	//Ask for the new speed and wheel diameter
	cout << "What is the new speed of the robot? ";
	cin >> newRPM;
	cout << endl;
	cout << "What is the new wheel diameter for the robots wheels? ";
	cin >> newDiameter;
	cout << endl;

	//Stores the user input if valid
	robot.setRPM(newRPM);

	//Call setDiameter to store the new diameter if valid
	robot.setDiameter(newDiameter);

	//Prints out current RPM, Diameter, and speed
	cout << "RPM: " << robot.getRPM() << endl;
	cout << "Diameter: " << robot.getDiameter() << endl;
	cout << "Speed: " << robot.getSpeed() << endl;

	return 0;


}
