#ifndef ROBOT_H
#define ROBOT_H

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "Graph.h"
# include "Point.h"
# include "Segment.h"

using namespace std;

class Robot
{
private:
	Segment* seg;
	int noOfSeg;

public:
	//Default constructor
	Robot()
	{
		seg = 0;
		noOfSeg = 0;
	}
	//setter function
	void setSegArray(Segment* newseg, int newn)
	{
		noOfSeg = newn;
		seg = new Segment[noOfSeg];
		seg = newseg;
	}
	//function to add segments 
	Segment* AddSegment(Segment* real, Segment* add, int n, int nAdd)
	{
		noOfSeg = n + nAdd;

		seg = new Segment[noOfSeg];

		int j = 0;
		for (int i = 0; i < noOfSeg; i++)
		{
			if (i < n)
			{
				seg[i] = real[i];
			}
			else
			{
				seg[i] = add[j];
				j++;
			}

		}

		for (int k = 0; k < noOfSeg; k++)
		{
			seg[k].print();
		}
		return(seg);
	}
	//function to delete the segments 
	void DeleteSegment(int nDelete)
	{
		Segment* temp;
		temp = new Segment[noOfSeg];

		for (int i = 0; i < noOfSeg; i++)
		{
			temp[i] = seg[i];
		}
		noOfSeg = noOfSeg - nDelete;
		seg = new Segment[noOfSeg];
		for (int i = 0; i < noOfSeg; i++)
		{
			seg[i] = temp[i];
		}
		for (int k = 0; k < noOfSeg; k++)
		{
			seg[k].print();
		}
		delete[]temp;
	}
	// functions to set to default pose
	void SetDefault(Point base)
	{
		for (int i = 0; i < noOfSeg; i++)
		{
			seg[i].setangle(0);
		}

		Point* Pt;
		Pt = new Point[noOfSeg + 1];
		Pt[0] = base;

		int b = 1;
		for (int a = 0; a < noOfSeg; a++)
		{
			if (a == 0)
			{
				seg[a].setStartPoint(Pt[0]);
				Pt[b] = seg[a].getEndpoint();
			}
			else
			{
				seg[a].setStartPoint(Pt[a]);
				Pt[b] = seg[a].getEndpoint();
			}
			b++;
		}
		for (int k = 0; k < noOfSeg; k++)
		{
			seg[k].print();
		}
		delete[] Pt;
	}
	int getNumberOfSeg()
	{
		return(noOfSeg);
	}
	void getPointArray(Point* Parray)
	{
		for (int i = 0; i < noOfSeg; i++)
		{
			Parray[i] = seg[i].getStartpoint();
		}
		Parray[noOfSeg] = seg[noOfSeg - 1].getEndpoint();
	}
	// to print the pose
	void PrintPose(Point* arr)
	{
		for (int i = 0; i <= noOfSeg-1; i++)
		{
			//Using a function from external graphics lib - opengl to draw the pose of the robot chain
			Graph(arr[i].getX(), arr[i].getY(), arr[i + 1].getX(), arr[i + 1].getY());
		}

	}
	Point ForwardKinematics(Point base, double* angles)
	{
		for (int i = 0; i < noOfSeg; i++)
		{
			seg[i].setangle(angles[i]);
		}

		Point* Pt;
		Pt = new Point[noOfSeg + 1];
		Pt[0] = base;

		int b = 1;
		for (int a = 0; a < noOfSeg; a++)
		{
			if (a == 0)
			{
				seg[a].setStartPoint(Pt[0]);
				Pt[b] = seg[a].getEndpoint();
			}
			else
			{
				seg[a].setStartPoint(Pt[a]);
				Pt[b] = seg[a].getEndpoint();
			}
			b++;
		}
		return(Pt[noOfSeg]);
		delete[] Pt;
	}

	//destructor
	~Robot()
	{
		delete[] seg;
	}
};
#endif