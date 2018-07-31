#pragma once

#include "Shape.h"
#include <vector>

enum Ops {
	plus,
	minus,
	mask,
	toggle
};

struct ListItem {
	Shape* s;
	Ops o;
};


class CSG {
public:
	CSG();
	~CSG();

	// Rule of 3: prevent use of copy, assign
	CSG(const CSG&) = delete;
	CSG &operator=(const CSG&) = delete;

	void RenderToFile(const char *filename, Point3D min, Point3D max, float widthInInches, int voxelsPerInch = 256);
	void Add(Shape *);
	void Subtract(Shape *);
	void Mask(Shape *);
	void Toggle(Shape *);

	CSG &operator+=(Shape *);
	CSG &operator-=(Shape *);
	CSG &operator&=(Shape *);
	CSG &operator^=(Shape *);

private:
	std::vector<ListItem> list;
	int listSize = 0;
};