
#ifndef VoxelModel_h
#define VoxelModel_h
#include <cstdint>

struct VoxelModel {
	int x;
	int y;
	int z;
	uint8_t* model;
};

int getIndex(const VoxelModel& model, int x, int y, int z);
void getXYZ(const VoxelModel& model, int index, int& x, int& y, int& z);
//VoxelModel emptyModel(int x, int y, int z);
//VoxelModel fullModel(int x, int y, int z);
bool getBit(const VoxelModel& model, int x, int y, int z);
void setBit(VoxelModel& model, int, int, int);
void clearBit(VoxelModel& model, int x, int y, int z);
void toggleBit(VoxelModel& model, int x, int y, int z);
VoxelModel allocateModel(int nx, int ny, int nz);
void clearModel(VoxelModel& model);
void fillModel(VoxelModel& model);
void deleteModel(VoxelModel& model);
void addSphere(VoxelModel& model, float, float, float, float);
void subtractSphere(VoxelModel& model, float, float, float, float);
void toggleSphere(VoxelModel& model, float, float, float, float);

#endif
