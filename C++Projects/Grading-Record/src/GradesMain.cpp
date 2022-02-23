#include "Grades.h"
#include <iostream>

using namespace std;

int main()
{
	int numStudents; //the number of students in the class
	int* scoreP = nullptr; //pointer for the dynamic array
	Grades obj; //Grades class object
	double average; //the average of every grade

	//Asks for user input for the number of students for the score array
	cout << "How many students are in the class?" << endl;
	cin >> numStudents;
	scoreP = new int [numStudents];

	//Calls each function of the Grades class to store, sort, avg, and print.
	obj.getGrades(scoreP, numStudents);
	obj.sortGrades(scoreP, numStudents);
	average = obj.avgGrades(scoreP, numStudents);
	obj.printGrades(scoreP, numStudents, average);
	
	


}
