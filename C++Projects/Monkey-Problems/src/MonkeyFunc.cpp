#include "Monkey.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Prints a table for the pounds of food eaten by each monkey on each day of the week
void Monkey::printArray(const double monkeys[numRows][numCols])
{
	cout << "Pounds of Food Eaten by Monkey and Day of Week" << endl;
	cout << endl;
	cout << "Monkey   " << "Sun   " << "Mon   " << "Tue   " << "Wed   " << "Thu   " << "Fri   " << "Sat" << endl;

	for (int r = 0; r < numRows; r++)
	{
		cout << setw(6) << r + 1 << "   ";

		for (int c = 0; c < numCols; c++)
		{
			if (!(c == 6))
			{
				cout << fixed << setprecision(1) << monkeys[r][c] << "   ";
			}
			else
				cout << fixed << setprecision(1) << monkeys[r][c] << endl;
		}
		
	}
	cout << endl;
}

//Calculates the average food eaten per day, as well as least and most food eaten
double Monkey::getAvgFood(const double monkeys[numRows][numCols], int num)
{
	double total = 0; //Accumalator for the total amount of food eaten
	double leastFood = monkeys[0][0]; //the least food eaten by any monkey
	double mostFood = monkeys[0][0]; //the most food eaten by any monkey

	switch (num)
	{

	case 1: //Calculates the average food eaten per day

		for (int r = 0; r < numRows; r++)
		{
			for (int c = 0; c < numCols; c++)
			{
				total += monkeys[r][c];
			}
		}

		return total / 7;

		break;

	case 2: //least food eaten finder

		for (int r = 0; r < numRows; r++)
		{
			for (int c = 0; c < numCols; c++)
			{
				if (monkeys[r][c] < leastFood)
				{
					leastFood = monkeys[r][c];
				}
			}
		}

		return leastFood;

		break;

	case 3: //Most food eaten finder

		for (int r = 0; r < numRows; r++)
		{
			for (int c = 0; c < numCols; c++)
			{
				if (monkeys[r][c] > mostFood)
				{
					mostFood = monkeys[r][c];
				}
			}
		}

		return mostFood;

		break;

	}
	
}

//Fills the monkeys array with user input for pounds of food eaten each day
void Monkey::inputFood(double monkeys[numRows][numCols])
{
	for (int r = 0; r < numRows; r++)
	{
		for (int c = 0; c < numCols; c++)
		{

			//asks for input for each day of the week
			switch (c)
			{
			case 0: //Sunday

				cout << "Enter pounds of food eaten by monkey " << r + 1 << " on Sun: ";
				cin >> monkeys[r][c];

				//validates user input
				if (monkeys[r][c] < 0)
				{
					cout << "Invalid input: Please enter a positive number of pounds of food: ";
					cin >> monkeys[r][c];
				}
				break;
				
			case 1: //Monday

				cout << "Enter pounds of food eaten by monkey " << r + 1 << " on Mon: ";
				cin >> monkeys[r][c];

				//validates user input
				if (monkeys[r][c] < 0)
				{
					cout << "Invalid input: Please enter a positive number of pounds of food: ";
					cin >> monkeys[r][c];
				}
				break;

			case 2: //Tuesday

				cout << "Enter pounds of food eaten by monkey " << r + 1 << " on Tue: ";
				cin >> monkeys[r][c];

				//validates user input
				if (monkeys[r][c] < 0)
				{
					cout << "Invalid input: Please enter a positive number of pounds of food: ";
					cin >> monkeys[r][c];
				}
				break;

			case 3: //Wednesday

				cout << "Enter pounds of food eaten by monkey " << r + 1 << " on Wed: ";
				cin >> monkeys[r][c];

				//validates user input
				if (monkeys[r][c] < 0)
				{
					cout << "Invalid input: Please enter a positive number of pounds of food: ";
					cin >> monkeys[r][c];
				}
				break;

			case 4: //Thursday

				cout << "Enter pounds of food eaten by monkey " << r + 1 << " on Thu: ";
				cin >> monkeys[r][c];

				//validates user input
				if (monkeys[r][c] < 0)
				{
					cout << "Invalid input: Please enter a positive number of pounds of food: ";
					cin >> monkeys[r][c];
				}
				break;

			case 5: //Friday

				cout << "Enter pounds of food eaten by monkey " << r + 1 << " on Fri: ";
				cin >> monkeys[r][c];

				//validates user input
				if (monkeys[r][c] < 0)
				{
					cout << "Invalid input: Please enter a positive number of pounds of food: ";
					cin >> monkeys[r][c];
				}
				break;

			case 6: //Saturday

				cout << "Enter pounds of food eaten by monkey " << r + 1 << " on Sat: ";
				cin >> monkeys[r][c];
				cout << endl;

				//validates user input
				if (monkeys[r][c] < 0)
				{
					cout << "Invalid input: Please enter a positive number of pounds of food: ";
					cin >> monkeys[r][c];
				}
				break;
			}
		}

		
	}
}
