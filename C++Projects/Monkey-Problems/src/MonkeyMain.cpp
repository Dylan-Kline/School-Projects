#include "Monkey.h"
#include <iostream>

using namespace std;

int main()
{
	Monkey monkeyObj; //Class object for the Monkey class
	double monkeys[numRows][numCols]; //Stores the pounds of food eaten by monkeys
	
	//Stores user input for the number of pounds eaten by each monkey each day
	monkeyObj.inputFood(monkeys);

	//Calls function to print the array table
	monkeyObj.printArray(monkeys);

	//Prints the average food eaten, least food eaten, and most food eaten
	cout << "The average food eaten per day by all monkeys    :   " << monkeyObj.getAvgFood(monkeys, 1) << " pounds" << endl;
	cout << "The least amount of food eaten by any monkey     :   " << monkeyObj.getAvgFood(monkeys, 2) << " pounds" << endl;
	cout << "The largest amount of food eaten by any monkey   :   " << monkeyObj.getAvgFood(monkeys, 3) << " pounds" << endl;
	
	return 0;
}
