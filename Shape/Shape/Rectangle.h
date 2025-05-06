#pragma once
#include "Shape.h"

class Rectangle final : public Shape
{
	Point p1, p2, p3, p4;

	void sides(double& side1, double& side2, double& side3, double& side4) const;

public:
	Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
	Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

	double getPerimeter() const override final;

	double getArea() const override final;

	bool containsPoint(const Point& point) const override final;

};

