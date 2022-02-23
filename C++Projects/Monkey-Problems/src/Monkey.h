#ifndef MONKEY_H
#define MONKEY_H


const int numRows = 3;
const int numCols = 7;


class Monkey
{
	
public:

	void printArray(const double monkeys[numRows][numCols]);
	double getAvgFood(const double monkeys[numRows][numCols], int);
	void inputFood(double monkeys[numRows][numCols]);



};

#endif
