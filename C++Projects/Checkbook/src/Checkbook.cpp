#include <iostream>
#include <iomanip>

using namespace std;

void CheckProcess(double& balance, const double serviceCharge, const double negativeCharge, const double lowBalanceCharge, double transAmount, double& totalCharges);
void DepositProcess(double& balance, const double serviceCharge, const double negativeCharge, const double lowBalanceCharge, double transAmount, double& totalCharges);

int main() {
	
	double balance, //used for keeping track of the balance throughout the program
		transAmount, //the amount for each transaction
		totalCharges; //Used to accumulate the total service charges 
	const double serviceCharge = 0.35; //constant for service charge
	const double negativeCharge = 30.00; //constant for a negative balance charge
	const double lowBalanceCharge = 10.00; //constant for a low balance charge
	char commands{}; //to store user input of the transaction type

	//prints the name of the program
	cout << "Checkbook Balancing Program\n";
	cout << endl;

	//User inputs beginning balance
	cout << "Enter the beginning balance: ";
	cin >> balance;
	cout << endl;




	//prints the commands for transaction types
	cout << "Commands:\n";
	cout << "C amount - process a check\n";
	cout << "D amount - process a deposit\n";
	cout << "E - end the program\n";
	cout << endl;

	//Initializes the total charges
	totalCharges = 0.0;


	//Loops until the command E or e is encountered
	while (commands != 'E' && commands != 'e') {

		//Print a messege prompt for the transaction type
		cout << "Enter a transaction type and amount: ";
		cin >> commands;

		//Asks for transaction amount only if commands is not e or E
		if (!(commands == 'E' || commands == 'e')) {

			cin >> transAmount; 

			//Validates transAmount and asks for input if invalid
			if (transAmount < 0) {

				cout << "Invalid input: Enter the transaction type and amount again: ";
				cin >> commands >> transAmount;
			}
		}

		//uses the user input to calculate the changes to balance
		switch (commands) {

		//Used for when user inputs the Check transaction type
		case 'c':
		case 'C':

			CheckProcess(balance, serviceCharge, negativeCharge, lowBalanceCharge, transAmount, totalCharges);
			break;

		//Used when user input command for Deposits
		case 'd':
		case 'D':

				
			DepositProcess(balance, serviceCharge, negativeCharge, lowBalanceCharge, transAmount, totalCharges);
			break;

		//Used to end the program and print out the total balance
		case 'e':
		case 'E':
			
			cout << "Processing end of month\n";

			balance -= totalCharges;

			cout << "Final balance: $" << fixed << setprecision(2) << balance;
			break;

		//Catches invalid input for the transaction type
		default:

			 
			cout << "Error: Invalid input, please make sure the input is within the menu.\n";
			break;

		}
	
	}
	return 0;
}

//Calculates the balance and service charges if the transaction type is a check
void CheckProcess(double& balance, const double serviceCharge, const double negativeCharge, const double lowBalanceCharge, double transAmount, double& totalCharges) {
	
	
	//Prints a processing message and the balance after the transaction
	cout << "Processing Check for $" << fixed << setprecision(2) << transAmount;
	cout << endl;

	balance -= transAmount;

	cout << "Balance: $" << fixed << setprecision(2) << balance;
	cout << endl;

	//Prints the service charge for a check and adds it to the total
	cout << "Service charge: $" << fixed << setprecision(2) << serviceCharge << " for a check";
	cout << endl;

	totalCharges += serviceCharge;

	//Checks if there is a need for additional service charges
	if (balance < 1000 && balance >= 0) {

		cout << "Service charge: $" << fixed << setprecision(2) << lowBalanceCharge << " balance below $1000.00" << endl;
		totalCharges += lowBalanceCharge;

	}
	else if (balance < 0) {

		cout << "Service charge: $" << fixed << setprecision(2) << negativeCharge << " balance is negative." << endl;
		totalCharges += negativeCharge;

	}

	//Print the total current service charges
	cout << "Total service charges: $" << fixed << setprecision(2) << totalCharges << endl;
	cout << endl;

}

//Calculates the balance and total service charges if the transaction type is a deposit
void DepositProcess(double& balance, const double serviceCharge, const double negativeCharge, const double lowBalanceCharge, double transAmount, double& totalCharges)
{
	//Prints a processing message
	cout << "Processing Deposit for $" << fixed << setprecision(2) << transAmount << endl;

	//Adds transaction amount to the balance
	balance += transAmount;
	cout << "Balance: $" << fixed << setprecision(2) << balance << endl;

	//Checks whether there is a need for additional service charges due to balance being too low
	if (balance < 1000 && balance >= 0) {

		cout << "Service charge: $" << fixed << setprecision(2) << lowBalanceCharge << " balance below $1000.00" << endl;
		totalCharges += lowBalanceCharge;

	}
	else if (balance < 0) {

		cout << "Service charge: $" << fixed << setprecision(2) << negativeCharge << " balance is negative." << endl;
		totalCharges += negativeCharge;

	}

	//Prints total current service charges
	cout << "Total service charges: $" << fixed << setprecision(2) << totalCharges << endl;
	cout << endl;

}
