#pragma once
#include "Shape.h"
#include "CSG.h"
#include <cmath>

class Cube : public Shape {
public:
	Cube(Point3D p, float r);
	~Cube();

	// Rule of 3: prevent use of copy, assign. Destructor is trivial anyway.
	Cube(const Cube&) = delete;
	Cube &operator=(const Cube&) = delete;

	bool InsideShape(Point3D p);
private:
	Point3D p;
	float r;
};


Cube::Cube(Point3D p, float r)
	:p(p), r(r) {}

Cube::~Cube() {}

bool Cube::InsideShape(Point3D p0)
{
	if (p0.x < p.x + r && p0.y < p.y + r && p0.z < p.z + r && p0.x > p.x - r && p0.y > p.y - r && p0.z > p.z - r) {
		return true;
	}
	return false;
}
