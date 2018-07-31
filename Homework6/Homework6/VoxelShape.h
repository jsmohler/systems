#ifndef VoxelShape_h
#define VoxelShape_h
#include <cstdint>
#include "BitVector.h"

class VoxelShape {
public:
	VoxelShape(int, int, int);
	~VoxelShape();
	void fillShape();
	void clearShape();
	int getX();
	int getY();
	int getZ();
	int getIndex(int a, int b, int c);
	void getXYZ(int index, int& a, int& b, int& c);
	bool getVoxel(int, int, int);
	void setVoxel(int, int, int);
	void clearVoxel(int, int, int);
	void toggleVoxel(int, int, int);
	void addSphere(float cx, float cy, float cz, float r);
	void subtractSphere(float cx, float cy, float cz, float r);
	void toggleSphere(float cx, float cy, float cz, float r);
private:
	int x;
	int y;
	int z;
	BitVector bv;
};

#endif
