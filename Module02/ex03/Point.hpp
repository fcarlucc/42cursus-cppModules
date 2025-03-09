#ifndef Point_HPP
#define Point_HPP

#include <cmath>
#include <iostream>
#include "Fixed.hpp"

class Point {

	private:
		const Fixed	x, y;

	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &toCopy);
		~Point();
		Point&  operator=(const Point &other);
		Fixed	getX() const;
		Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Fixed	sign(Point const p1, Point const p2, Point const p3);

#endif
