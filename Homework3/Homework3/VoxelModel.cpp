//
//  voxelModel.cpp
//  Homework2
//
//  Created by Ben Jones on 1/4/17.
//  Copyright © 2017 Ben Jones. All rights reserved.
//

#include "VoxelModel.h"
#include <iostream>

uint8_t getIndex(int x, int y, int z) {
	return x * 16 + y * 4 + z;
	//or return x << 4 | y << 2 | z
}
uint8_t getX(uint8_t index) {
	return index >> 4;
}
uint8_t getY(uint8_t index) {
	return (index >> 2) & 0x3;
}
uint8_t getZ(uint8_t index) {
	return index & 0x3;
}

uint64_t emptyModel() {
	return 0;
}
uint64_t fullModel() {
	return 0xFFFFFFFFFFFFFFFF;
}
bool getBit(uint64_t model, int x, int y, int z) {
	//shift 1 to the appropriate spot.  If that bit is a 1, you won't get a 0 after anding
	return (model & (uint64_t{ 1 } << getIndex(x, y, z))) != 0;
}

uint64_t setBit(uint64_t model, int x, int y, int z) {
	uint8_t index = getIndex(x, y, z);
	return model | (uint64_t{ 1 } << index);

}
uint64_t clearBit(uint64_t model, int x, int y, int z) {
	uint8_t index = getIndex(x, y, z);

	return model & ~(uint64_t{ 1 } << index);
}
uint64_t toggleBit(uint64_t model, int x, int y, int z) {

	if (getBit(model, x, y, z)) {
		return clearBit(model, x, y, z);
	}
	else {
		return setBit(model, x, y, z);
	}

}
