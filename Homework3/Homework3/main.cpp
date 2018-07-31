#include <iostream>
#include "VoxelModel.h"
#include "surfaceExtraction.hpp"

/*
	Jordan Mohler
	Comp 2355
	Homework 3
	1 February 2017
*/

int main(int argc, char* argv[]) {
	uint64_t model = fullModel();
	writeSTL(model, "voxels.stl");
	return 0;
}