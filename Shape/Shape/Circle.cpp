#include "Circle.h"

void Circle::R(double& R) const
{
	R = distance(O, p);

}

Circle::Circle(Point O, Point p)
{
	this->O = O;
	this->p = p;
}

Circle::Circle(int Ox, int Oy, int px, int py)
{
	O.x = Ox;
	O.y = Oy;

	p.x = px;
	p.y = py;
}

double Circle::getPerimeter() const
{
	double radius;
	R(radius);

	return 2 * PI * radius;
}

double Circle::getArea() const
{
	double radius;
	R(radius);

	return PI * radius * radius;
}

bool Circle::containsPoint(const Point& point) const
{
	return distance(O, point) < distance(O, p);
}
