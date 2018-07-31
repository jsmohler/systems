#ifndef surfaceExtraction_h
#define surfaceExtraction_h
#include <cstdint>
#include "MyArray.hpp"
#include "SharedQueue.h"

enum FaceType {
    NX,
    NY,
    NZ,
    PX,
    PY,
    PZ
};

struct Triangle{
    float normal[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

struct Range {
	int i, j;
};

void writeSTL(VoxelShape& model, const char* filename);
void extractFace(int x, int y, int z, FaceType face, Triangle& t1, Triangle& t2);
void ThreadWorker(SharedQueue<Range> *workQueue, MyArray<Triangle> &arr, VoxelShape& model, std::mutex* lock);
void overZ(int i, int j, VoxelShape& model, MyArray<Triangle>& arr);

#endif


