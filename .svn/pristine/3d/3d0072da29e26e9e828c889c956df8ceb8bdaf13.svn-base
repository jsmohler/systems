#include <iostream>
#include "VoxelModel.h"
#include <cassert>
using std::cout;

/*
	Jordan Mohler
	COMP 2355
	Homework 2
	23 January 2017

*/

int main(int argc, char* argv[]) {
	uint64_t j = fullModel();
	cout << std::hex;
	
	for (int i = 0; i < 64; i++) {
		assert(getIndex(getX(i), getY(i), getZ(i)) == i);
	}
	for (int i = 0; i < 4; i++) {
		assert(getX(getIndex(getX(i), getY(i), getZ(i))) == getX(i));
        assert(getY(getIndex(getX(i), getY(i), getZ(i))) == getY(i));
        assert(getZ(getIndex(getX(i), getY(i), getZ(i))) == getZ(i));
	}

	cout << "Start model:" << j;
	
	cout << "\nClear third bit: ";
	j = clearBit(j, getX(0), getY(0), getZ(3));
	cout << j;

	cout << "\nReset third bit: ";
	j = setBit(j, getX(0), getY(0), getZ(3));
	cout << j;

	cout << "\nToggle fourth bit: ";
	j = toggleBit(j, 0, 1, 0);
	cout << j;

	cout << "\nToggle first bit: ";
	j = toggleBit(j, 0, 0, 0);
	cout << j;

	cout << "\nFinal model:" << j;
	return 0;
}
