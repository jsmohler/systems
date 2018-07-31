#include "VoxelModel.h"
#include <iostream>

uint8_t getIndex(int x, int y, int z) {
	return (x * 16) + (y * 4) + z;
};

uint8_t getX(uint8_t index) {
	return index / 16;
};

uint8_t getY(uint8_t index) {
	return (index % 16) / 4;
};

uint8_t getZ(uint8_t index) {
	int x = index / 16;
	int y = (index % 16) / 4;
	return index - (x*16) - (y*4);
};

uint64_t emptyModel() {
	return 0x0000000000000000;
};

uint64_t fullModel() {
	return 0xFFFFFFFFFFFFFFFF;
};

bool getBit(uint64_t model, int x, int y, int z) {
	model = model >> getIndex(x, y, z);
	if (model % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
};

uint64_t setBit(uint64_t model, int x, int y, int z) {
	if (! getBit(model, x, y, z)) {
		int k = 1 << getIndex(x, y, z);
		return k ^ model;
	}
	return model;
};

uint64_t clearBit(uint64_t model, int x, int y, int z) {
	if (getBit(model, x, y, z)) {
		int k = 1 << getIndex(x, y, z);
		return k ^ model;
	}
	return model;
};

uint64_t toggleBit(uint64_t model, int x, int y, int z) {
	if (getBit(model, x, y, z)) {
		return clearBit(model, x, y, z);
	}
	else {
		return setBit(model, x, y, z);
	}
};
