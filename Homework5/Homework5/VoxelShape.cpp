#include <iostream>
#include <cstdint>
#include "VoxelShape.h"


VoxelShape::VoxelShape(int a, int b, int c) : bv(a*b*c) {
	x = a;
	y = b;
	z = c;
}

VoxelShape::~VoxelShape() {
	x = 0;
	y = 0;
	z = 0;
}

int VoxelShape::getX() {
	return x;
}
int VoxelShape::getY() {
	return y;
}

int VoxelShape::getZ() {
	return z;
}

void VoxelShape::fillShape() {
	bv.fill();
}

void VoxelShape::clearShape() {
	bv.clear();
}

bool VoxelShape::getVoxel(int a, int b, int c) {
	return bv.get(getIndex(a, b, c));
}

void VoxelShape::setVoxel(int a, int b, int c) {
	bv.set(getIndex(a, b, c), true);
}

void VoxelShape::clearVoxel(int a, int b, int c) {
	bv.set(getIndex(a, b, c), false);
}

void VoxelShape::toggleVoxel(int a, int b, int c) {
	if (getVoxel(a, b, c)) {
		clearVoxel(a, b, c);
	}
	else {
		setVoxel(a, b, c);
	}
}

void VoxelShape::addSphere(float cx, float cy, float cz, float r) {
	for (int i = cx - r; i < cx + r; i++) {
		for (int j = cy - r; j < cy + r; j++) {
			for (int k = cz - r; k < cz + r; k++) {
				if (i < x && i >= 0 && j < y && j >= 0 && k < z && k >= 0 && (pow((i - cx), 2) + pow((j - cy), 2) + pow((k - cz), 2) < pow(r, 2))) {
					setVoxel(i, j, k);
				}
			}
		}
	}
}

void VoxelShape::subtractSphere(float cx, float cy, float cz, float r){
	for (int i = cx - r; i < cx + r; i++) {
		for (int j = cy - r; j < cy + r; j++) {
			for (int k = cz - r; k < cz + r; k++) {
				if (i < x && i >= 0 && j < y && j >= 0 && k < z && k >= 0 && (pow((i - cx), 2) + pow((j - cy), 2) + pow((k - cz), 2) < pow(r, 2))) {
					clearVoxel(i, j, k);
				}
			}
		}
	}
}

void VoxelShape::toggleSphere(float cx, float cy, float cz, float r) {
	for (int i = cx - r; i < cx + r; i++) {
		for (int j = cy - r; j < cy + r; j++) {
			for (int k = cz - r; k < cz + r; k++) {
				if (i < x && i >= 0 && j < y && j >= 0 && k < z && k >= 0 && (pow((i - cx), 2) + pow((j - cy), 2) + pow((k - cz), 2) < pow(r, 2))) {
					toggleVoxel(i, j, k);
				}
			}
		}
	}
}

int VoxelShape::getIndex(int a, int b, int c) {
	return (a * y * z) + (b * z) + c;
};

void VoxelShape::getXYZ(int index, int& a, int& b, int& c) {
	a = index / (y * z);
	b = (index % (y * z)) / z;
	c = index - ((a * y * z) + b * z);
};
