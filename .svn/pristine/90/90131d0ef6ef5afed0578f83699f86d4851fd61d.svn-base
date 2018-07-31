//
//  surfaceExtraction.cpp
//  Homework7
//
//  Created by Jordan Mohler
//

#define _CRT_SECURE_NO_WARNINGS
#include "VoxelShape.h"
#include "surfaceExtraction.hpp"
#include <iostream>
#include <cstdint>
#include "MyArray.hpp"
#include "SharedQueue.h"
#include <thread>
#include <mutex>

void overZ(int i, int j, VoxelShape& model, MyArray<Triangle>& arr);

void ThreadWorker(SharedQueue<Range> *workQueue, MyArray<Triangle> &arr, VoxelShape& model, std::mutex* lock)
{
	Range r;
	MyArray<Triangle> temp(20);
	// read work from queue
	while (true) {
		while (workQueue->Remove(r) == false) {
			std::this_thread::yield();
		}

		// if x==y==-1, then this is a quit message; we are done
		if ((r.i == -1) && (r.j == -1)) { break; }

		//extract triangles and put them in the array
		overZ(r.i, r.j, model, temp);
	}

	lock->lock();
	for (int d = 0; d < temp.size(); d++) {
		arr.PushBack(temp.get(d));
	}
	lock->unlock();
}

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

void overZ(int i, int j, VoxelShape& model, MyArray<Triangle>& arr) {
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

void writeSTL(VoxelShape& model, const char* filename) {
	MyArray<Triangle> arr(20);
	SharedQueue<Range> sq;
	std::mutex lock;
	std::thread** threads;
	int numThreads = std::thread::hardware_concurrency();
	threads = new std::thread*[numThreads];
	for (int x = 0; x < numThreads; x++)
	{
		threads[x] = new std::thread(ThreadWorker, &sq, std::ref(arr), std::ref(model), &lock);
	}

	Range r;
	for (int i = 0; i < model.getX(); i++) {
		for (int j = 0; j < model.getY(); j++) {
			r = { i, j };
			sq.Add(r);
		}
	}
	for (int j = 0; j < numThreads; j++) {
		Range k = { -1, -1 };
		sq.Add(k);
	}

	for (int x = 0; x < numThreads; x++)
	{
		threads[x]->join();
		delete threads[x];
	}
	delete[] threads;
	

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


