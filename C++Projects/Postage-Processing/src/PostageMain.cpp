#include "Postage.h"
#include <iostream>

using namespace std;

int main()
{
	const int numEles = 15; //Size of the shipChg array
	int pckWeight, //Weight of package
		side1, //Dimension 1 of package
		side2, //Dimension 2 of package
		side3; //Dimension 3 of package
	double shippingCost; //The cost of shipping the package
	Postage post; //used to access Postage class functions
	
	//Initializes the shipping charge array
	PckInfo shipChg[numEles] = { {1, 1.50}, {2, 2.10},
		{3, 4.00}, {5, 6.75}, {7, 9.90}, {10, 14.95}, {13, 19.40}, {16, 24.20}, {20, 27.30},
		{25, 31.90}, {30, 38.50}, {35, 43.50}, {40, 44.80}, {45, 47.40}, {50, 55.20} };

	//Initializes pckWeight to start the loop
	pckWeight = 0;

	//Displays the details needed to be inputted by user
	cout << "For each transaction, enter package weight and 3 dimensions." << endl;
	cout << "Enter -1 to quit." << endl;
	cout << endl;

	//Displays the transaction info based on user input for weight and dimensions.
	while (pckWeight != -1)
	{
		//Asks for input for package weight
		cout << "Enter package weight and 3 dimensions: ";
		cin >> pckWeight;
		cout << endl;

		//Displays the transaction info such as shipping cost for the package if input is valid
		if (pckWeight != -1 && pckWeight > 0)
		{
			cin >> side1 >> side2 >> side3;
			
			if (side1 > 0 && side2 > 0 && side3 > 0)
			{

				shippingCost = post.findCost(shipChg, numEles, pckWeight);
				post.transCalc(shipChg, pckWeight, side1, side2, side3, shippingCost);
				
			}else
				cout << "Error - package weight and dimensions must be larger than 0 \nPlease re-enter transaction\n" << endl;
		}
		else if (pckWeight < -1) {
			cout << "Error - package weight and dimensions must be larger than 0 \nPlease re-enter transaction\n" << endl;
		}
			
		
		
	}

	//End of program. Displays the number of accepted and rejected packages.
	cout << "Number of accepted packages: " << post.getNumAccepted() << endl;
	cout << "Number of rejected packages: " << post.getNumRejected() << endl;
	cout << endl;

	return 0;

}
