#include <iostream>
#include "CSG.h"
#include "VoxelShape.h"
#include "SurfaceExtraction.hpp"
#include "Shape.h"
#include <cmath>

CSG::CSG() {}

CSG::~CSG() {
	for (int i = 0; i < listSize; i++) {
		delete list[i].s;
	}
}


void CSG::RenderToFile(const char *filename, Point3D min, Point3D max, float widthInInches, int voxelsPerInch) {
	float xDiff = widthInInches;
	float yDiff = abs(max.y - min.y) * (widthInInches / abs(max.x - min.x));
	float zDiff = abs(max.z - min.z) * (widthInInches / abs(max.x - min.x));

	int x = xDiff*voxelsPerInch;
	int y = yDiff*voxelsPerInch;
	int z = zDiff*voxelsPerInch;

	//Make voxel model
	VoxelShape vm(x, y, z);
	vm.clearShape();

	//Iterate through and fill based on list commands
	for (int m = 0; m < listSize; m++) {
		ListItem temp = list[m];
		if (temp.o == plus) {
			for (float i = 0; i < x; i++) {
				for (float j = 0; j < y; j++) {
					for (float k = 0; k < z; k++) {
						Point3D p((i / voxelsPerInch) + min.x, (j / voxelsPerInch) + min.y, (k / voxelsPerInch) + min.z);
						if ((temp.s)->InsideShape(p)) {
							vm.setVoxel(i, j, k);
						}
					}
				}
			}
		}
		else if (temp.o == minus) {
			for (float i = 0; i < x; i++) {
				for (float j = 0; j < y; j++) {
					for (float k = 0; k < z; k++) {
						Point3D p((i / voxelsPerInch) + min.x, (j / voxelsPerInch) + min.y, (k / voxelsPerInch) + min.z);
						if ((temp.s)->InsideShape(p)) {
							vm.clearVoxel(i, j, k);
						}
					}
				}
			}
		} else if (temp.o == mask) {
			for (float i = 0; i < x; i++) {
				for (float j = 0; j < y; j++) {
					for (float k = 0; k < z; k++) {
						Point3D p((i / voxelsPerInch) + min.x, (j / voxelsPerInch) + min.y, (k / voxelsPerInch) + min.z);
						if (! (temp.s)->InsideShape(p)) {
							vm.clearVoxel(i, j, k);
						}
					}
				}
			}
		} else if (temp.o == toggle) {
			for (float i = 0; i < x; i++) {
				for (float j = 0; j < y; j++) {
					for (float k = 0; k < z; k++) {
						Point3D p((i / voxelsPerInch) + min.x, (j / voxelsPerInch) + min.y, (k / voxelsPerInch) + min.z);
						if ((temp.s)->InsideShape(p)) {
							vm.toggleVoxel(i, j, k);
						}
					}
				}
			}
		}
	}

	//Call Write STL
	writeSTL(vm, filename);

}

void CSG::Add(Shape *shape) {
	ListItem temp;
	temp.s = shape;
	temp.o = plus;
	list.push_back(temp);
	listSize++;
}

void CSG::Subtract(Shape *shape) {
	ListItem temp;
	temp.s = shape;
	temp.o = minus;
	list.push_back(temp);
	listSize++;
}

void CSG::Mask(Shape *shape) {
	ListItem temp;
	temp.s = shape;
	temp.o = mask;
	list.push_back(temp);
	listSize++;
}

void CSG::Toggle(Shape *shape) {
	ListItem temp;
	temp.s = shape;
	temp.o = toggle;
	list.push_back(temp);
	listSize++;
}

CSG & CSG::operator+=(Shape *s) {
	Add(s);
	return *this;
}

CSG & CSG::operator-=(Shape *s) {
	Subtract(s);
	return *this;
}

CSG & CSG::operator&=(Shape *s) {
	Mask(s);
	return *this;
}

CSG & CSG::operator^=(Shape *s) {
	Toggle(s);
	return *this;
}