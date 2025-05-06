#pragma once
#include "Shape.h"
#define PI 3.14

class Circle final: public Shape
{
	Point O;
	Point p;

	void R(double& R) const;

public:
	Circle(Point O, Point p);
	Circle(int Ox, int Oy, int px, int py);

	double getPerimeter() const override final;

	double getArea() const override final;

	bool containsPoint(const Point& point) const override final;

};

