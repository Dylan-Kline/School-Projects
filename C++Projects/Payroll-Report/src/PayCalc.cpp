#include "PayCalc.h"


//Constructor
PayCalc::PayCalc()
{
	totalGross = 0.0;
	totalNet = 0.0;
	grossPay = 0.0;
	payTax = 0.0;
	netPay = 0.0;
	insurance = 0;
	tax = 0.0;
}

//Calculates gross pay depending on the type of employee
double PayCalc::calcGross(int type, double rate, double hours)
{
	
	if (type == 0)
	{
		if (hours <= 40)
		{
			grossPay = hours * rate;
		}
		else if (hours > 40)
		{
			grossPay = ((40 * rate) + ((hours - 40) * (rate * 1.5)));
		}
	}
	else
		grossPay = hours * rate;

	totalGross += grossPay;

	return grossPay;

}

//Calculates the net pay
double PayCalc::calcNet()
{
	netPay = grossPay - (tax + insurance);

	totalNet += netPay;

	return netPay;
}

//Calculates taxed income
double PayCalc::calcTax(double incomeTax)
{
	tax = (grossPay * incomeTax);
	payTax = grossPay - tax;

	return payTax;
}

//Calculates Insurance
int PayCalc::calcInsurance(int dependents)
{
	insurance = dependents * 20;

	return insurance;
}



//Returns total gross pay
double PayCalc::getTotalGross()
{
	return totalGross;
}

//Returns total net pay
double PayCalc::getTotalNet()
{
	return totalNet;
}
