//
//  surfaceExtraction.cpp
//  Homework3
//
//  Created by Ben Jones on 1/6/17.
//  Copyright © 2017 Ben Jones. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include "VoxelShape.h"
#include "surfaceExtraction.hpp"
#include <iostream>
#include <cstdint>
#include "MyArray.hpp"

void writeTwoTriangles(MyArray<Triangle> &arr, VoxelShape& model, int x, int y, int z, int index, FaceType face) {
	Triangle t1, t2;
	if ((x > model.getX() - 1|| x < 0 || y > model.getY() - 1 || y < 0 || z > model.getZ() - 1 || z < 0 || ! model.getVoxel(x, y, z))) {
		int getX, getY, getZ;
		model.getXYZ(index, getX, getY, getZ);
		extractFace(getX, getY, getZ, face, t1, t2);
		arr.PushBack(t1);
		arr.PushBack(t2);
	}
	
}

void writeSTL(VoxelShape& model, const char* filename) {
	MyArray<Triangle> arr(20);
	for (int i = 0; i < model.getX(); i++) {
		for (int j = 0; j < model.getY(); j++) {
			for (int k = 0; k < model.getZ(); k++) {
				if (model.getVoxel(i, j, k)) {
					writeTwoTriangles(arr, model, i - 1, j, k, model.getIndex(i, j, k), NX);
					writeTwoTriangles(arr, model, i + 1, j, k, model.getIndex(i, j, k), PX);
					writeTwoTriangles(arr, model, i, j - 1, k, model.getIndex(i, j, k), NY);
					writeTwoTriangles(arr, model, i, j + 1, k, model.getIndex(i, j, k), PY);
					writeTwoTriangles(arr, model, i, j, k - 1, model.getIndex(i, j, k), NZ);
					writeTwoTriangles(arr, model, i, j, k + 1, model.getIndex(i, j, k), PZ);
				}
			}
		}
	}


	FILE *f = fopen(filename, "wb+");
	char* header = new char[80];
	for (int i = 0; i < 80; i++) {
		header[i] = 0;
	}
	fwrite(header, 80, 1, f);
	delete[] header;

	uint32_t numTri = arr.size();
	fwrite(&numTri, sizeof(numTri), 1, f);

	uint16_t pad = 0;
	Triangle temp;
	for (int i = 0; i < arr.size(); i++) {
		temp = arr.get(i);
		fwrite(&temp, sizeof(Triangle), 1, f);
		fwrite(&pad, sizeof(pad), 1, f);
	}
	fclose(f);
}


inline void fillPlane(int a1, int a2, int b1, int b2, int c, int cInd, Triangle& t1, Triangle& t2){
    t1.v1[cInd] = c;
    t2.v1[cInd] = c;
    t1.v2[cInd] = c;
    t2.v2[cInd] = c;
    t1.v3[cInd] = c;
    t2.v3[cInd] = c;
    int aInd = (cInd +1) % 3;
    int bInd = (cInd +2) % 3;
    
    t1.v1[aInd] = a1;
    t1.v2[aInd] = a2;
    t1.v3[aInd] = a2;
    
    t2.v1[aInd] = a1;
    t2.v2[aInd] = a2;
    t2.v3[aInd] = a1;
    
    t1.v1[bInd] = b1;
    t1.v2[bInd] = b1;
    t1.v3[bInd] = b2;
    
    t2.v1[bInd] = b1;
    t2.v2[bInd] = b2;
    t2.v3[bInd] = b2;
    
}

void extractFace(int x, int y, int z, FaceType face, Triangle& t1, Triangle& t2){
    for(int i= 0; i < 3; i++){
        t1.normal[i] = 0;
        t2.normal[i] = 0;
    }
    switch(face){
        case NX:
            t1.normal[0] = -1;
            t2.normal[0] = -1;
            fillPlane(y + 1, y, z, z+1, x, 0, t1, t2);
            break;
        case NY:
            t1.normal[1] = -1;
            t2.normal[1] = -1;
            fillPlane(z + 1, z, x, x+1, y, 1, t1, t2);
            break;
        case NZ:
            t1.normal[2] = -1;
            t2.normal[2] = -1;
            fillPlane(x + 1, x, y, y + 1, z, 2, t1, t2);
            break;
        case PX:
            t1.normal[0] = 1;
            t2.normal[0] = 1;
            fillPlane(y, y + 1, z, z +1, x + 1, 0, t1, t2);
            break;
        case PY:
            t1.normal[1] = 1;
            t2.normal[1] = 1;
            fillPlane(z, z + 1, x, x + 1, y + 1, 1, t1, t2);
            break;
        case PZ:
            t1.normal[2] = 1;
            t2.normal[2] = 1;
            fillPlane(x, x +1, y, y + 1, z + 1, 2, t1, t2);
            break;
    }
}


