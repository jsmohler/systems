/*
	Jordan Mohler
	COMP 2355
	Homework 4
	13 February 2017
*/

#include <iostream>
#include "VoxelModel.h"
#include "surfaceExtraction.hpp"

int main(int argc, char* argv[]) {
	VoxelModel vm = allocateModel(50, 50, 50);
	fillModel(vm);
	subtractSphere(vm, 25, 25, 25, 20);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			clearBit(vm, i, 23, j);
			clearBit(vm, i, 24, j);
			clearBit(vm, i, 25, j);
			clearBit(vm, i, 26, j);
			clearBit(vm, i, 27, j);
			clearBit(vm, 23, i, j);
			clearBit(vm, 24, i, j);
			clearBit(vm, 25, i, j);
			clearBit(vm, 26, i, j);
			clearBit(vm, 27, i, j);
			clearBit(vm, i, j, 23);
			clearBit(vm, i, j, 24);
			clearBit(vm, i, j, 25);
			clearBit(vm, i, j, 26);
			clearBit(vm, i, j, 27);
		}
	}
	toggleSphere(vm, 25, 25, 25, 10);
	writeSTL(vm, "VoxelModel.stl");
	deleteModel(vm);

	return 0;
}