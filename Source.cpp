//*********************************************************************//
//** Author: Sanjana Vijayakumar Nambiar                             **//
//** Date Created: December 4, 2021                                  **//
//** Assignment 4: Robot Kinematics                                  **//
//** ENGR-UH 1000 Computer Programming for Engineers, NYUAD          **//
//** Problem: Robot Kinematics                                       **//
//*********************************************************************//

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
//including the external header files to draw the graphs 
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "Graph.h"
// include the point, segment and robot class header files
# include "Point.h"
# include "Segment.h"
# include "Robot.h"

using namespace std;

int main()
{
	// Program description
	cout << " ********************************************************************* " << endl;
	cout << "                         ROBOT KINEMATICS                              " << endl;
	cout << " ********************************************************************* " << endl;

	int n;
	cout << "Please enter the number of segments" << endl;
	cin >> n;

	// declaring Segment pointer for dynamic array memory allocation. 
	Segment* seg;
	seg = new Segment[n];

	double x = 0, y = 0;
	cout << "Please enter the coordinates of the base point or the starting point" << endl;
	cin >> x >> y;
	Point Base(x, y);
	
	// declaring Point pointer for dynamic array memory allocation. 
	Point* Pt;
	Pt = new Point[n + 1];
	Pt[0] = Base;

	for (int i = 0, j = 1; i < n; i++, j++)
	{
		double length;
		cout << "Please enter the length of segment " << j << endl;
		cin >> length;
		if (length < 0)// printing error if the user provides invalid data input
		{
			cerr << "Error! length must be greater than zero" << endl;
			exit (-1);
		}
		seg[i].setlen(length);//using the class function to set the length of the segments 
	}

	for (int l = 0, k = 1; l < n; l++, k++)
	{
		double angle;
		cout << "Please enter the angle(in radians) associated with the segment " << k << endl;
		cin >> angle;
		seg[l].setangle(angle);//using the class function to set the angles of the segments 
	}

	int b = 1;
	for (int a = 0; a < n; a++)
	{
		if (a == 0)
		{
			// using the Segment class function to set the start point of the segments
			seg[a].setStartPoint(Pt[0]);
			// using the segment class function to get the end point of the segments
			Pt[b] = seg[a].getEndpoint();
		}
		else
		{
			// using the Segment class function to set the start point of the segments
			seg[a].setStartPoint(Pt[a]);
			// using the Segment class function to get the end point of the segments
			Pt[b] = seg[a].getEndpoint();
		}
		b++;
	}

	for (int i = 0; i < n; i++)
	{
		seg[i].print();
	}

	Point EndEffector = Pt[n];

	//Creating a robot object R1
	Robot R1;
	R1.setSegArray(seg, n);//Calling function to set the segment array

	//Providing user the option to add 
	char choice1;
	cout << "Enter 'y' for adding a segment or 'n' for not adding a segment to the original array of segments" << endl;
	cin >> choice1;

	if (choice1 == 'y')
	{
		int nToAdd;
		cout << "Please enter the number segments to add" << endl;
		cin >> nToAdd;

		// declaring Segment pointer for dynamic array memory allocation. 
		Segment* segToAdd;
		segToAdd = new Segment[nToAdd];

		// declaring Point pointer for dynamic array memory allocation. 
		Point* dot;
		dot = new Point[nToAdd + 1];
		dot[0] = EndEffector;

		for (int i = 0, j = 1; i < nToAdd; i++, j++)
		{
			double len;
			cout << "Please enter the length of segment " << j << endl;
			cin >> len;
			if (len < 0)
			{
				cerr << "Error! length must be greater than zero" << endl;
				exit(-1);
			}
			segToAdd[i].setlen(len);
		}

		for (int l = 0, k = 1; l < nToAdd; l++, k++)
		{
			double angl;
			cout << "Please enter the angle (in radians) associated with the segment " << k << endl;
			cin >> angl;
			segToAdd[l].setangle(angl);
		}

		for (int a = 0, b = 1; a < nToAdd; a++)
		{
			if (a == 0)
			{
				// using the Segment class function to set the start point of the segments
				segToAdd[a].setStartPoint(dot[0]);
				// using the Segment class function to get the end point of the segments
				dot[b] = segToAdd[a].getEndpoint();
			}
			else
			{
				// using the Segment class function to set the start point of the segments
				segToAdd[a].setStartPoint(dot[a]);
				// using the Segment class function to get the end point of the segments
				dot[b] = segToAdd[a].getEndpoint();
			}
			b++;
		}

		R1.AddSegment(seg, segToAdd, n, nToAdd);//function calling for adding segments 
		EndEffector = dot[nToAdd];
		//de-allocating the dynamic memory allocations
		delete[] segToAdd;
		delete[] dot;
	}
	else
	{
		cout << "No segment has been added" << endl;
	}

	//Providing user the option to delete
	char choice2;
	cout << "Enter 'y' for deleting any segments or 'n' for not deleting any segments from the original array of segments" << endl;
	cin >> choice2;
	if (choice2 == 'y')
	{
		int nToDelete;
		cout << "Please enter the number segmnets to delete" << endl;
		cin >> nToDelete;

		R1.DeleteSegment(nToDelete);//function calling for deleting segments 
	}
	else
	{
		cout << "No segments has been deleted" << endl;
	}

	//Providing user the option to set to default pose
	char choice3;
	cout << "Enter 'y' for setting the segments to default position or 'n' for not setting" << endl;
	cin >> choice3;
	if (choice3 == 'y')
	{
		R1.SetDefault(Base);//function calling for setting to default pose 
	}
	else
	{
		cout << "The segments hasn't changed to default position" << endl;
	}
	
	int num;
	num = R1.getNumberOfSeg();

	// declaring Point pointer for dynamic array memory allocation. 
	Point* Parr = new Point[num + 1];
	R1.getPointArray(Parr);
	EndEffector = Parr[num];

	//Providing user the option to print the current pose
	char choice4;
	cout << "Enter 'y' for printing the current pose of the robot chain or 'n' for not printing" << endl;
	cin >> choice4;
	if (choice4 == 'y')
	{
		R1.PrintPose(Parr);//function calling to print the pose
	}
	else
	{
		cout << "The segments are not printed" << endl;
	}

	//Providing user the option to calculate the end effector
	char choice5;
	cout << "Enter 'a' for performing the forward kinematics for the existing angles\n"
		<< "Enter 'b' for performing forward kinematics for a new set of angles\n"
		<< "Enter 'c' for not performing forward kinematics" << endl;
	cin >> choice5;
	if (choice5 == 'a')
	{
		cout << "The End Effector of the existing robot chain is : ";
		EndEffector.print();
	}
	else if (choice5 == 'b')
	{
		// declaring pointer for dynamic array memory allocation. 
		double* Ang;
		Ang = new double[num];
		Point End;
		for (int i = 0; i < num; i++)
		{
			cout << "Please enter " << i+1 << " new angles (in radians) for getting the End Effector" << endl;
			cin >> Ang[i];
			End =  R1.ForwardKinematics(Base, Ang); //Robot class function calling to calculate the endeffector for a new array of angles
		}
		cout << "The End Effector for the new set of angles : ";
		End.print();
		//de-allocating the dynamic memory allocations
		delete[] Ang;
	}
	else
	{
		cout << "The End Effector is not printed" << endl;
	}
	
	//Program ended description
	cout << " ********************************************************************* " << endl;
	cout << "                            !!THANK YOU!!                              " << endl;
	cout << "                     THE PROGRAM HAS BEEN EXECUTED                     " << endl;
	cout << " ********************************************************************* " << endl;

	//de-allocating the dynamic memory allocations
	delete[] Pt;
	delete[] Parr;
	delete[] seg;
	return 0;
}
