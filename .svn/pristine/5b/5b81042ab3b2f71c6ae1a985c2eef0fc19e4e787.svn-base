#include <iostream>
#include "VoxelShape.h"
#include "surfaceExtraction.hpp"

/*
	Jordan Mohler
	Comp 2355
	Homework 6
	27 February 2017
*/

int main(int argc, char* argv[]) {
	VoxelShape vox(50, 50, 50);
	vox.clearShape();
	vox.addSphere(25, 25, 50, 25);
	vox.addSphere(25, 25, 0, 25);
	vox.addSphere(25, 0, 25, 25);
	vox.addSphere(25, 50, 25, 25);


	writeSTL(vox, "VoxelShape.stl");

	return 0;
}