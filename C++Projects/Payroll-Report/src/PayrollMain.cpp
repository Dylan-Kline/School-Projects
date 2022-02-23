#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "PayCalc.h"


using namespace std;

int main()
{

	const int numOfEmps = 99; //used for the number of employees in the payroll report
	const double taxRate = .15; //15% tax rate
	double hours, //Number of hours an employee worked
		hourlyRate; //Rate of pay
	Employee masterInfo[numOfEmps]; //Employee master info array
	Employee searchObj;
	PayCalc obj; //PayCalc object
	ifstream masterFile; //Master info file
	ifstream transFile; //Transaction file
	ofstream payReportFile; //Payroll report
	int id, //Employee ID
		numDeps, //Number of dependents
		type, //Employee type
		positionID,
		processes = 0; //Number of successful processes
	char empName[21] = {},
		gender;
	
	
	masterFile.open("master10.txt");
	transFile.open("trans10.txt");
	payReportFile.open("PayRollReport.txt");

	if (!(masterFile.fail()) && !(transFile.fail()))
	{
		for (int i = 0; i < numOfEmps; i++)
		{
			//Reads from the master info file
			masterFile >> id;
			masterFile.get(empName, 21, '\n');
			masterFile >> hourlyRate >> numDeps >> type >> gender;
			masterInfo[i].set(id, empName, hourlyRate, numDeps, type);

		}
	
		//Start of Payroll report
		payReportFile.clear();
		payReportFile << "Payroll Report\n";
		payReportFile << "\n";
		payReportFile << "ID " << setw(21) << left << "Employee name" << setw(10) << right << "Gross Pay"
			<< setw(10) << right << "Tax" << setw(10) << right << "Insurance" << setw(8) << right << "Net Pay" << endl;

		//Error Report
		cout << "No matching record for id or the hours entered are not positive:" << endl;
		cout << endl;


		//Calculates the gross pay, tax, and net pay for each employee.
		while(!transFile.eof())
		{
			transFile >> id;
			transFile >> hours;

			if (!transFile.eof())
			{
				positionID = searchObj.searchID(masterInfo, id);

				if (positionID >= 0)
				{

					if (!(masterInfo[positionID].getID()) == 0 && !(hours <= 0) && !(id == 0))
					{

						//Prints the payroll report in the PayRollReport file
						payReportFile << setw(2) << masterInfo[positionID].getID() << setw(21) << masterInfo[positionID].getName();
						payReportFile << fixed << setprecision(2);

						payReportFile << setw(11) << right << obj.calcGross(masterInfo[positionID].getType(), masterInfo[positionID].getHourlyPay(), hours);
						payReportFile << setw(10) << right << obj.calcTax(taxRate);
						payReportFile << setw(10) << right << obj.calcInsurance(masterInfo[positionID].getNumDeps());
						payReportFile << setw(8) << right << obj.calcNet();
						payReportFile << endl;

						processes++;
					}
					else
					{
						cout << id << " " << hours << endl;

					}
				}
				else
					cout << id << " " << hours << endl;
			}
				
			
		}

		//Prints total gross and net pay, as well as the number of successful processes during the program
		payReportFile << endl;
		payReportFile << setw(17) << left << "Total Gross Pay :" << " " << obj.getTotalGross() << endl;
		payReportFile << setw(17) << left << "Total Net Pay   :" << " " << obj.getTotalNet() << endl;
		cout << endl;
		cout << "Number of successful processes: " << processes << endl;

	}
	else
		cout << "Files failed to open.\n";

	masterFile.close();
	transFile.close();
	payReportFile.close();

	return 0;
}
