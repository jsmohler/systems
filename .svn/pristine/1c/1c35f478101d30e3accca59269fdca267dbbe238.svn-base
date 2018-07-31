#include <iostream>
#include "FunTimes.h"

/*
	Jordan Mohler
	Comp 2355
	Lab 8
	1 February 2017
*/

int main(int argc, char* argv[]) {

	readAndPrint<int>("int");
	readAndPrint<uint64_t>("uint64_t");
	readAndPrint<uint32_t>("uint32_t");
	readAndPrint<uint16_t>("uint16_t");
	readAndPrint<uint8_t>("uint8_t");
	
	//Using struct causes conversion error because cout/cin doens't know how to handle it
	/*struct num {
		int x;
	};

	readAndPrint<num>("num");*/


	//Also cannot convert pointers 
	/*int* a;
	int x;
	a = &x;

	readAndPrint<int*>("int*");*/

	return 0;
}