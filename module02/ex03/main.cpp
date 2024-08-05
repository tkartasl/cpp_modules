/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:10:41 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/02 15:55:42 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
	Point const a(0.0, 0.0);
	Point const b(10.0, 30.0);
	Point const c(20.0, 0.0);
	Point const p(10.0, 15.0);
	Point const a1(0.0, 0.0);
	Point const b1(10.0, 30.0);
	Point const c1(20.0, 0.0);
	Point const p1(30.0, 15.0);
	
	if (bsp( a, b, c, p ) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;
	if (bsp( a1, b1, c1, p1 ) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;
	//p1 = p;
	if (bsp( a1, b1, c1, p1 ) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;		
	return (0);
}