#include <iostream>
#include "VoxelShape.h"
#include "surfaceExtraction.hpp"
#include "Timer.h"

/*
	Jordan Mohler
	Comp 2355
	Homework 7
	6 March 2017
*/

int main(int argc, char* argv[]) {
	VoxelShape vox(50, 50, 50);
	vox.clearShape();
	vox.addSphere(40, 40, 40, 10);
	vox.addSphere(10, 10, 10, 10);

	Timer t;
	t.StartTimer();
	writeSTL(vox, "VoxelShape.stl");
	t.EndTimer();
	std::cout << "Elapsed Time: " << t.GetElapsedTime();

	return 0;
}