#pragma once
#include "Shape.h"
#include "CSG.h"
#include <cmath>

class Sphere : public Shape {
public:
	Sphere(Point3D p, float r);
	~Sphere();

	// Rule of 3: prevent use of copy, assign. Destructor is trivial anyway.
	Sphere(const Sphere&) = delete;
	Sphere &operator=(const Sphere&) = delete;

	bool InsideShape(Point3D p);
private:
	Point3D p;
	float r;
};


Sphere::Sphere(Point3D p, float r)
	:p(p), r(r) {}

Sphere::~Sphere() {

}

bool Sphere::InsideShape(Point3D p0)
{
	if ((pow((p0.x - p.x), 2) + pow((p0.y - p.y), 2) + pow((p0.z - p.z), 2) < pow(r, 2))) {
		return true;
	}
	return false;
}
