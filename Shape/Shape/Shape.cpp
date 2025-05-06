#include "Shape.h"

double Shape::distance(const Point& p1, const Point& p2)
{
	return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y));
}
