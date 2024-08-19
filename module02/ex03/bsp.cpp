/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:45:34 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/19 10:51:51 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float	calculateArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float	res;
	res = roundf((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
	if (res < 0)
		res *= -1;
	return res;
}

bool	compareVertices(Point const& first, Point const& second)
{
	if (first.getX() == second.getX() && first.getY() == second.getY())
		return true;
	else
		return false;
}

bool	isPointOnEdge(Point const& vertice1, Point const& vertice2, Point const& point)
{
	float	x = point.getX().toFloat();
	float	y = point.getY().toFloat();
	float	x1 = vertice1.getX().toFloat();
	float	y1 = vertice1.getY().toFloat();
	float	x2 = vertice2.getX().toFloat();
	float	y2 = vertice2.getY().toFloat();
	
	float result = 	(y2 - y1) * x - (x2 - x1) * y + (x2 * y1 - y2 * x1);
	
	if (result != 0)
		return false;
	
	if (point.getX() >= Fixed::min(vertice1.getX(), vertice2.getX()) && point.getX() <= Fixed::max(vertice1.getX(), vertice2.getX())
		&& point.getY() >= Fixed::min(vertice1.getY(), vertice2.getY()) && point.getY() <= Fixed::max(vertice1.getY(), vertice2.getY()))
		return true;
	
	return false;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float area = 0.0;
	float area1 = 0.0;
	float area2 = 0.0;
	float area3 = 0.0;

	if (compareVertices(point, a) == true || compareVertices(point, b) == true || compareVertices(point, c) == true)
		return false;

	if (isPointOnEdge(a, b, point) == true || isPointOnEdge(b, c, point) == true || isPointOnEdge(c, a, point) == true)
		return false;

	area = calculateArea(a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	area1 = calculateArea(point.getX().toInt(), point.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	area2 = calculateArea(a.getX().toInt(), a.getY().toInt(), point.getX().toInt(), point.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	area3 = calculateArea(a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt(), point.getX().toInt(), point.getY().toInt());
	return (area == (area1 + area2 + area3));
}