#include <iostream>
#include <Windows.h>
#include <List>
#include <Vector>

// Week 1 functions
void DataSetter(unsigned int* storageData, int shiftSpaces[], unsigned int number, int valueOrder) {

	int totalShiftSpaces = 0;
	valueOrder--;

	for (int i = 0; i < valueOrder; i++)
	{
		totalShiftSpaces += shiftSpaces[i];
	}

	*storageData |= (number << totalShiftSpaces);
}
unsigned int DataGetter(unsigned int dat, int shiftSpaces[], int selectedNumber) {

	int totalShiftSpaces = 0;

	for (int i = 0; i < selectedNumber; i++)
	{
		totalShiftSpaces += shiftSpaces[i];
	}

	//num[0] = dat & ~(UINT_MAX << shiftSpaces[0]);

	//num[0] = dat & ((1 << shiftSpaces[0]) - 1);
	//num[1] = (dat >> shiftSpaces[0]) & ((1 << shiftSpaces[1]) - 1);
	//num[2] = (dat >> shiftSpaces[0] + shiftSpaces[1]) & ((1 << shiftSpaces[2]) - 1);
	//num[3] = (dat >> shiftSpaces[0] + shiftSpaces[1] + shiftSpaces[2]) & ((1 << shiftSpaces[3]) - 1);

	return (dat >> totalShiftSpaces) & ((1 << shiftSpaces[selectedNumber]) - 1);
}

void Week1() {

	unsigned int numStorage[4] = { 0 };
	//7		0 - 15,	4 bits
	//1		0 - 1,	1 bit
	//30	0 - 31,	5 bits
	//0		0 - 1,	1 bit

	int shiftSpaces[4];
	shiftSpaces[0] = 4;
	shiftSpaces[1] = 1;
	shiftSpaces[2] = 5;
	shiftSpaces[3] = 1;

	unsigned int dat = 0;

	// Initialization 
	// Pack num1 - num4 into data variable
	// Manual setter
	DataSetter(&dat, shiftSpaces, 8, 1);
	DataSetter(&dat, shiftSpaces, 0, 2);
	DataSetter(&dat, shiftSpaces, 31, 3);
	DataSetter(&dat, shiftSpaces, 1, 4);

	// Extract num1 - num4 from data variable
	for (int i = 0; i < 4; i++)
	{
		numStorage[i] = DataGetter(dat, shiftSpaces, i);
		std::cout << numStorage[i] << std::endl;
	}
}

int main() {

	Week1();

	return 0;
}