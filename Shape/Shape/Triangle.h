#pragma once
#include "Shape.h"

class Triangle final: public Shape
{

	Point p1, p2, p3;
	
	void sides(double& side1, double& side2, double& side3) const;

public:
	Triangle(Point p1, Point p2, Point p3);
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);


	double getPerimeter() const override final;

	double getArea() const override final;

	bool containsPoint(const Point& point) const override final;

};

