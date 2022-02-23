#ifndef POSTAGE_H
#define POSTAGE_H

struct PckInfo
{

	int weight; //The weight of the package
	double costs; //Shipping cost depending on the weight of the package

};

class Postage
{
	
private:

	int rejectedPcks, //Accumalator for the number of rejected packages
		acceptedPcks, //Accumalator for the number of accepted packages
		numOfTrans; //Accumalator for the number of transactions made

public:

	//Initializes the counters of the number of transactions, accepeted packages, and rejected packages
	Postage()
	{
		rejectedPcks = 0; 
		acceptedPcks = 0;
		numOfTrans = 0;
	}

	void transCalc(const PckInfo array[], int weight, int side1, int side2, int side3, double shipCost);
	int getNumRejected();
	int getNumAccepted();
	double findCost(const PckInfo array[], int size, int weight);

};

#endif
