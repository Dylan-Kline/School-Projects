#include "Grades.h"
#include <iostream>
#include <iomanip>

using namespace std;


/*
Inputs grades into the scores array
*/
void Grades::getGrades(int* scores, int numStudents)
{
	int testGrade; //Holds user input for grades

	for (int i = 0; i < numStudents; i++)
	{
		cout << "Please enter the test grades for student " << i + 1 << endl;
		cin >> testGrade;

		if (testGrade < 0 || testGrade > 105)
		{
			cout << "Invalid test grade entered: Test grades must be between 0 - 105." << endl;
		}

		*(scores + i) = testGrade;
	}
	
}

//Sorts the scores into ascending order
void Grades::sortGrades(int* scores, int numStudents)
{
	int minIndex,
		minValue;

	for(int start = 0; start < (numStudents - 1); start++)
	{
		minIndex = start;
		minValue = *(scores + start);

		for (int i = start + 1; i < numStudents; i++)
		{
			if (*(scores + i) < minValue)
			{
				minValue = *(scores + i);
				minIndex = i;
			}
		}

		swap(*(scores + minIndex), *(scores + start));
	}
}

//Averages out the grades in the scores array
double Grades::avgGrades(int* scores, int numStudents)
{
	double total = 0.0, //total grades
	 avg; //average of all grades

	for (int i = 0; i < numStudents; i++)
	{
		total += *(scores + i);
	}

	avg = total / numStudents;

	return avg;
}

//Prints out the grades in scores into a table
void Grades::printGrades(int* scores, int numStudents, double avgGrade)
{
	cout << setw(13) << right << "Grade" << endl;
	cout << setw(13) << right << "-----" << endl;
	
	for (int i = 0; i < numStudents; i++)
	{
		cout << setw(13) << right << *(scores + i) << endl;
	}

	cout << setw(13) << right << "-----" << endl;
	cout << setw(8) << left << "Average ";
	cout << setw(5) << right << avgGrade << endl;
}
