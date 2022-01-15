#include "util.h"

Vec2D::Vec2D(int p_X, int p_Y) : x(p_X), y(p_Y) {}

//I cant fucking get operator overloading working
//bool Vec2D::operator==(const Vec2D& l, const Vec2D& r)
//{
//	return (l.x == r.x && l.y == r.y);
//}
