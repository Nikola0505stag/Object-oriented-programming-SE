#include "Rectangle.h"
#include "Triangle.h"

void Rectangle::sides(double& side1, double& side2, double& side3, double& side4) const
{
	side1 = distance(p1, p2);
	side2 = distance(p1, p4);
	side3 = distance(p2, p3);
	side4 = distance(p3, p4);

}

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	p1.x = x1;
	p1.y = y1;

	p2.x = x2;
	p2.y = y2;

	p3.x = x3;
	p3.y = y3;

	p4.x = x4;
	p4.y = y4;
}

double Rectangle::getPerimeter() const
{
	double side1, side2, side3, side4;
	sides(side1, side2, side3, side4);

	return side1 + side2 + side3 + side4;
}

double Rectangle::getArea() const 
{
	double side1, side2, side3, side4;
	sides(side1, side2, side3, side4);

	return side1 * side2;
}

bool Rectangle::containsPoint(const Point& point) const
{
	double area1, area2, area3, area4;

	area1 = Triangle(point, p1, p2).getArea();
	area2 = Triangle(point, p1, p4).getArea();
	area3 = Triangle(point, p2, p3).getArea();
	area4 = Triangle(point, p3, p4).getArea();

	double originalArea = getArea();

	return std::abs((area1 + area2 + area3 + area4) - originalArea) < 1e-6;
}
