//
// Created by Konstantin Kuchenmeister on 07/23/2021
// 
// Visitor.h
// 
// Is a derived class from the static visitor, that is able to apply a x and y offset to shapes and move them in two-dimensional space.
// 
//

#ifndef QUANTNET_HW_VISITOR_H
#define QUANTNET_HW_VISITOR_H


#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <boost/variant/static_visitor.hpp>

using namespace KonstantinK::CAD;

class Visitor : public boost::static_visitor<void> {
private:
	// Offset
	double m_dx;
	double m_dy;

public:
	/// <summary>
	/// Create a visitor object that allows to set the private offset variables.
	/// </summary>
	/// <param name="newXOffset">The wanted x offset.</param>
	/// <param name="newYOffset">The wanted y offset.</param>
	Visitor(double newXOffset, double newYOffset) : m_dx{ newXOffset }, m_dy{ newYOffset } {};

	/// <summary>
	/// Visits a point and moves the point throughout the space.
	/// </summary>
	void operator () (Point& p) const
	{
		// Manipulate the x and y coordinates of the point
		p.X(p.X() + m_dx);
		p.Y(p.Y() + m_dy);
	}

	/// <summary>
	/// Visits a line and moves the line throughout the space.
	/// </summary>
	void operator () (Line& l) const
	{
		Point sp = l.P1();
		Point ep = l.P2();

		// Manipulate the x and y coordinate of the startpoint
		sp.X(sp.X() + m_dx);
		sp.Y(sp.Y() + m_dy);

		// Manipulate the x and y coordinate of the endpoint
		ep.X(ep.X() + m_dx);
		ep.Y(ep.Y() + m_dy);

		l.P1(sp);
		l.P2(ep);

	}

	/// <summary>
	/// Visits a circle and moves the circle throughout the space.
	/// </summary>
	void operator () (Circle& c) const
	{
		Point cp = c.CentrePoint();

		// Move the center point of the circle
		cp.X(cp.X() + m_dx);
		cp.Y(cp.Y() + m_dy);

		c.CentrePoint(cp);
	}
};

#endif