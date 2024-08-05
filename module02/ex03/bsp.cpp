/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:45:34 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/02 16:02:34 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float	calculateArea(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return ((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool	bsp( Point const a, Point const b, Point const c, Point const p)
{
	float area = 0.0;
	float area1 = 0.0;
	float area2 = 0.0;
	float area3 = 0.0;
	
	area = calculateArea(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
	area = calculateArea(p.getX().toFloat(), p.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
	area = calculateArea(a.getX().toFloat(), a.getY().toFloat(), p.getX().toFloat(), p.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
	area = calculateArea(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), p.getX().toFloat(), p.getY().toFloat());
	return (area == (area1 + area2 + area3));
}