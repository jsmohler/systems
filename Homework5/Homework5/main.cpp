#include <iostream>
#include "VoxelShape.h"
#include "surfaceExtraction.hpp"

/*
	Jordan Mohler
	Comp 2355
	Homework 5
	20 February 2017
*/

int main(int argc, char* argv[]) {
	VoxelShape vox(50, 50, 50);
	vox.clearShape();
	vox.addSphere(25, 25, 25, 25);
	vox.subtractSphere(15, 15, 15, 10);

	writeSTL(vox, "VoxelShape.stl");

	return 0;
}