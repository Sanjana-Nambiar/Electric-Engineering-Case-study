#ifndef POINT_H
#define POINT_H

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "Graph.h"

using namespace std;

class Point
{
private:
	double X;
	double Y;

public:
	//Default constructor
	Point()
	{
		X = 0;
		Y = 0;
	}
	//non - Default constructor
	Point(double iniX, double iniY)
	{
		X = iniX;
		Y = iniY;
	}
	//getter functions
	double getX()
	{
		return(X);
	}
	double getY()
	{
		return(Y);
	}
	//setter functions
	void setX(double newX)
	{
		X = newX;
	}
	void setY(double newY)
	{
		Y = newY;
	}
	void setXY(double setx, double sety)
	{
		X = setx;
		Y = sety;
	}
	//service function
	void print()
	{
		cout << "(" << X << "," << Y << ")" << endl;
	}
};
#endif