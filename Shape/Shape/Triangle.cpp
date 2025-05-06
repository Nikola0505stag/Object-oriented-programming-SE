#include "Triangle.h"

void Triangle::sides(double& side1, double& side2, double& side3) const
{
	side1 = distance(p1, p2);
	side2 = distance(p1, p3);
	side3 = distance(p2, p3);
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	p1.x = x1;
	p1.y = y1;

	p2.x = x2;
	p2.y = y2;
	
	p3.x = x3;
	p3.y = y3;
}

double Triangle::getPerimeter() const
{
	double side1, side2, side3;

	sides(side1, side2, side3);

	return side1 + side2 + side3;
}

double Triangle::getArea() const
{
	double side1, side2, side3;
	sides(side1, side2, side3);

	double area;
	double p = (side1 + side2 + side3) / 2;
	area = std::sqrt(p * (p - side1) * (p - side2) * ( p - side3));
	return area;
}

bool Triangle::containsPoint(const Point& point) const
{
	double area1, area2, area3;
	double originalArea = getArea();

	area1 = Triangle(point, p2, p3).getArea();
	area2 = Triangle(p1, point, p3).getArea();
	area3 = Triangle(p1, p2, point).getArea();

	return std::abs((area1 + area2 + area3) - originalArea) < 1e-6;
}
