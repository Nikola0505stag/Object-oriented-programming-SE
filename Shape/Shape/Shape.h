#pragma once
#include <iostream>

struct Point {
	int x = 0;
	int y = 0;
};

class Shape
{


protected:
	static double distance(const Point& p1, const Point& p2);

public:
	virtual double getPerimeter() const = 0;
	virtual double getArea() const  = 0;
	virtual bool containsPoint(const Point& point) const = 0;


	virtual ~Shape() = default;
};

