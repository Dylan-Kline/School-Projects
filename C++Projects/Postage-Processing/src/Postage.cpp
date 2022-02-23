#include "Postage.h"
#include <iomanip>
#include <iostream>

using namespace std;

//Handles the transaction processing for user inputted package weight, and dimensions.
void Postage::transCalc(const PckInfo array[], int weight, int side1, int side2, int side3, double shipCost)
{
	int girth, //The girth of the package
		largestSide; //The largest side of the package
	
	numOfTrans++; 

	//Determines the largest of the three dimensions
	if (side1 >= side2 && side1 >= side3)
	{
		largestSide = side1;
		girth = (side1 + side2 + side3 - largestSide) * 2;
	}
	else if (side2 >= side1 && side2 >= side3)
	{
		largestSide = side2;
		girth = (side1 + side2 + side3 - largestSide) * 2;
	}
	else
		largestSide = side3;
		girth = (side1 + side2 + side3 - largestSide) * 2;

	
	//Prints the message of a rejected transaction
	if (weight > 50)
	{
		rejectedPcks += 1;

		//Displays output for a rejected transaction
		cout << "Transaction:" << setw(10)  << right << numOfTrans << endl;
		cout << setw(11) << left << "Status" << ":" << setw(10) << right << "Rejected" << endl;
		cout << setw(11) << left << "Weight" << ":" << setw(10) << right << weight << endl;
		cout << setw(11) << left << "Cost" << ":" << setw(10) << right << "-" << endl;
		cout << endl;
	}
	else if (side1 > 36 || side2 > 36 || side3 > 36)
	{
		rejectedPcks += 1;

		//Displays output for a rejected transaction
		cout << "Transaction:" << setw(10) << right << numOfTrans << endl;
		cout << setw(11) << left << "Status" << ":" << setw(10) << right << "Rejected" << endl;
		cout << setw(11) << left << "Weight" << ":" << setw(10) << right<< weight << endl;
		cout << setw(11) << left << "Cost" << ":" << setw(10) << right << "-" << endl;
		cout << endl;
	}
	else if (girth > 60)
	{
		rejectedPcks += 1;

		//Displays output for a rejected transaction
		cout << "Transaction:" << setw(10) << right << numOfTrans << endl;
		cout << setw(11) << left << "Status" << ":" << setw(10) << right << "Rejected" << endl;
		cout << setw(11) << left << "Weight" << ":" << setw(10) << right << weight << endl;
		cout << setw(11) << left << "Cost" << ":" << setw(10) << right<< "-" << endl;
		cout << endl;
	}
	else
	{
		acceptedPcks += 1;

		//Displays output for accepted packages
		cout << "Transaction:" << setw(10) << right << numOfTrans << endl;
		cout << setw(11) << left << "Status" << ":" << setw(10) << right << "Accepted" << endl;
		cout << setw(11) << left << "Weight" << ":" << setw(10) << right << weight << endl;
		cout << setw(11) << left << "Cost" << ":" << setw(10) << right << shipCost << endl;
		cout << endl;
	}

	
}

//Returns the number of rejected packages throughout the transactions made
int Postage::getNumRejected()
{
	return rejectedPcks;
}

//Returns the number of accepted packages throughout the transactions made
int Postage::getNumAccepted()
{
	return acceptedPcks;
}

//Searches for the shipping cost based on the weight of the package
double Postage::findCost(const PckInfo array[], int size, int weight)
{
	int first = 0,
		last = size - 1,
		middle;
	double costOfShipping{};
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle].weight == weight)
		{
			found = true;
			costOfShipping = array[middle].costs;
		}
		else if (array[middle].weight > weight && array[middle - 1].weight < weight)
		{
			found = true;
			costOfShipping = array[middle].costs;
		}
		else if (array[middle].weight > weight)
		{
			last = middle - 1;
		}
		else
			first = middle + 1;
	}
	return costOfShipping;
}
