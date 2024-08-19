/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:10:41 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/19 10:54:30 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
	Point const a(Point( 0.0f, 0.0f ));
	Point const b(Point( 10.0f, 30.0f ));
	Point const c(Point( 20.0f, 0.0f ));
	Point const p(Point( 10.0f, 15.0f ));
	Point const p1(Point( 30.0f, 15.0f ));
	Point const p2(Point( 15.0f, 15.0f ));
	Point const p3(Point( 0.0f, 1.0f ));
	Point const p4(Point( 5.0f, 15.0f ));
	Point const p5(Point( 5.0f, 1.0f ));

	if (bsp(a, b, c, p) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;
	if (bsp(a, b, c, p1) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;
	if (bsp(a, b, c, p2) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;
	if (bsp(a, b, c, p3) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;
	if (bsp(a, b, c, p4) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;
	if (bsp(a, b, c, p5) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is not inside the triangle" << std::endl;	
	return (0);
}