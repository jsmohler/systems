#include "VoxelModel.h"
#include <iostream>


int getIndex(const VoxelModel& model, int x, int y, int z) {
	return (x * model.y * model.z) + (y * model.z) + z;
};

void getXYZ(const VoxelModel& model, int index, int& x, int& y, int& z) {
	x = index / (model.y * model.z);
	y = (index % (model.y * model.z)) / model.z;
	z = index - ((x * model.y * model.z) + y * model.z);
};

//VoxelModel emptyModel(int x, int y, int z) {
//	VoxelModel vm = allocateModel(x, y, z);
//	for (int i = 0; i < x*y*z; i++) {
//		vm.model[i] = 0;
//	}
//	return vm;
//};
//
//VoxelModel fullModel(int x, int y, int z) {
//	VoxelModel vm = allocateModel(x, y, z);
//	for (int i = 0; i < x*y*z; i++) {
//		vm.model[i] = 0xFF;
//	}
//	return vm;
//};

int getByteNumber(int index) {
	return index / 8;
};

uint8_t getBitNumber(int index) {
	return index % 8; 
};

bool getBit(const VoxelModel& model, int x, int y, int z) {
	const int index = getByteNumber(getIndex(model, x, y, z));
	uint8_t bits = model.model[index];
	bits = bits >> getBitNumber(getIndex(model, x, y, z));
	if (bits % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
};

void setBit(VoxelModel& model, int x, int y, int z) {
	const int index = getByteNumber(getIndex(model, x, y, z));
	uint8_t bits = model.model[index];
	uint8_t k = 1 << getBitNumber(getIndex(model, x, y, z));
	bits = bits | k;
	model.model[index] = bits;
};

void clearBit(VoxelModel& model, int x, int y, int z) {
	const int index = getByteNumber(getIndex(model, x, y, z));
	uint8_t bits = model.model[index];
	uint8_t k = 1 << getBitNumber(getIndex(model, x, y, z));
	bits = bits & (~k);
	model.model[index] = bits;
};

void toggleBit(VoxelModel& model, int x, int y, int z) {
	if (getBit(model, x, y, z)) {
		clearBit(model, x, y, z);
	}
	else {
		setBit(model, x, y, z);
	}
};

VoxelModel allocateModel(int nx, int ny, int nz) {
	VoxelModel vm;
	vm.model = new uint8_t[nx*ny*nz];
	vm.x = nx;
	vm.y = ny;
	vm.z = nz;
	return vm;
};

void clearModel(VoxelModel& model) {
	for (int i = 0; i < model.x * model.y * model.z; i++) {
		model.model[i] = 0;
	}
};

void fillModel(VoxelModel& model) {
	for (int i = 0; i < model.x * model.y * model.z; i++) {
		model.model[i] = 0xFF;
	}
};

void deleteModel(VoxelModel& model) {
	delete[] model.model;
	model.model = nullptr;
	model.x = 0;
	model.y = 0;
	model.z = 0;
};

void addSphere(VoxelModel& model, float cx, float cy, float cz, float r) {
	for (int i = cx - r; i < cx + r; i++) {
		for (int j = cy - r; j < cy + r; j++) {
			for (int k = cz - r; k < cz + r; k++) {
				if (i < model.x && i >= 0 && j < model.y && j >= 0 && k < model.z && k >= 0 && (pow((i - cx), 2) + pow((j - cy), 2) + pow((k - cz), 2) < pow(r, 2))) {
					setBit(model, i, j, k);
				}
			}
		}
	}
};

void subtractSphere(VoxelModel& model, float cx, float cy, float cz, float r) {
	for (int i = cx - r; i < cx + r; i++) {
		for (int j = cy - r; j < cy + r; j++) {
			for (int k = cz - r; k < cz + r; k++) {
				if (i < model.x && i >= 0 && j < model.y && j >= 0 && k < model.z && k >= 0 && (pow((i - cx), 2) + pow((j - cy), 2) + pow((k - cz), 2) < pow(r, 2))) {
					clearBit(model, i, j, k);
				}
			}
		}
	}
};

void toggleSphere(VoxelModel& model, float cx, float cy, float cz, float r) {
	for (int i = cx - r; i < cx + r; i++) {
		for (int j = cy - r; j < cy + r; j++) {
			for (int k = cz - r; k < cz + r; k++) {
				if (i < model.x && i >= 0 && j < model.y && j >= 0 && k < model.z && k >= 0 && (pow((i - cx), 2) + pow((j - cy), 2) + pow((k - cz), 2) < pow(r, 2))) {
					toggleBit(model, i, j, k);
				}
			}
		}
	}
};

