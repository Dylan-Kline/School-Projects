#ifndef PAYCALC_H
#define PAYCALC_H

class PayCalc
{

private:

	double totalGross, //Total gross pay
		totalNet, //Total net pay
		grossPay, //Gross pay
		payTax, //income tax
		tax,
		netPay; //Net pay
	int insurance; //Insurance total
	

public:

	PayCalc();
	
	double calcGross(int, double, double);
	double calcNet();
	double calcTax(double);
	int calcInsurance(int);
	double getTotalGross();
	double getTotalNet();

};




#endif
