#ifndef SEGMENT_H
#define SEGMENT_H

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "Graph.h"
# include "Point.h"

using namespace std;

class Segment
{
private:
	double len;
	double angle;
	Point pointS;
	Point pointE;

public:
	//Default constructor
	Segment()
	{
		len = 0;
		angle = 0;
	}
	//non - Default constructor
	Segment(double inilen, double iniangle, Point newpointS)
	{
		len = inilen;
		if (inilen < 0)
		{
			cout << "Length must be greater than zero" << endl;
			len = 1;
		}

		angle = iniangle;
		pointS = newpointS;
	}
	//getter functions
	double getlen()
	{
		return(len);
	}
	double getangle()
	{
		return(angle);
	}
	Point getStartpoint()
	{
		return(pointS);
	}
	//setter functions
	void setlen(double newlen)
	{
		len = newlen;
		if (newlen < 0)
		{
			cout << "Length must be greater than zero" << endl;
			len = 1;
		}
	}
	void setangle(double newangle)
	{
		angle = newangle;
	}
	void setStartPoint(Point P)
	{
		pointS = P;
	}
	//function to calculate the end point
	Point getEndpoint()
	{
		double x1, y1, x2, y2;

		//using point class functions to calculate th end point 
		x1 = pointS.getX();
		y1 = pointS.getY();

		x2 = x1 + len * cos(angle);
		y2 = y1 + len * sin(angle);

		pointE.setXY(x2, y2);
		return(pointE);
	}
	// service function to print the the segment information
	void print()
	{
		cout << "The following are the segment informations : " << endl;
		cout << "\tThe length of the segment = " << len << endl;
		cout << "\tThe angle made by the segment = " << angle << endl;
		cout << "\tThe start point of the segment = ";
		pointS.print();
		cout << "\tThe end point of the segment = ";
		pointE.print();
	}
};
#endif