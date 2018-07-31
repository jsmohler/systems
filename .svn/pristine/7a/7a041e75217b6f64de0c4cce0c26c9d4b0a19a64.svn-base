#include <iostream>
#include "VoxelShape.h"
#include "surfaceExtraction.hpp"
#include "CSG.h"
#include "Timer.h"
#include "Cube.h"
#include "Sphere.h"
#include "Line.h"

/*
	Jordan Mohler
	Comp 2355
	Homework 8
	15 March 2017
*/
void RenderBallInBall()
{
	CSG csg;
	Point3D middle = {0.0, 0.0, 0.0};
	Point3D lb = {-1, -1, -1};
	Point3D ub = {1, 1, 1};
	
	// Initial hollow sphere
	csg += new Sphere(middle, 1.0);
	csg ^= new Sphere(middle, 0.76);

	// 5 of 6 sides cut out (not bottom)
	csg -= new Sphere({ 1.0, 0.0,  0.0}, 0.4);
	csg -= new Sphere({-1.0, 0.0,  0.0}, 0.4);
	csg -= new Sphere({0.0,  1.0,  0.0}, 0.4);
	csg -= new Sphere({0.0, -1.0,  0.0}, 0.4);
	csg -= new Sphere({0.0,  0.0,  1.0}, 0.4);

	// Trim edges with cube
	csg &= new Cube(middle, 0.8);

	// Add floating ball in middle
	csg += new Sphere(middle, 0.44);

	Timer t;
	t.StartTimer();
	csg.RenderToFile("ballinball_064.stl", lb, ub, 2.0, 64);
	t.EndTimer();
	printf("%1.2fs total time elapsed\n", t.GetElapsedTime());

}

int main(int argc, char* argv[]) {
	RenderBallInBall();
	return 0;
}