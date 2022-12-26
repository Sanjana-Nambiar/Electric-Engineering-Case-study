# Electric Engineering Case study
## Step 1: Problem Identification and Statement 
The aim is to design of a software to simulate the motion of a multi-degree of freedom kinematic chains 
that form the structure of a robotic system. The emphasis on geometry means that the links of the robot 
are modeled as rigid bodies and its joints are assumed to provide pure rotation, (though this program is 
meant for 2D rotation). This program facilitates to add or delete any number of segments, set the 
segments to default position, get the end effector and print the orientation of segments. 

## Step 2: Gathering of Information and Input/output Description 
#### Relevant information: 
Forward kinematics refers to the use of the kinematic equations of a robot to compute the position of 
the end-effector from specified values for the joint parameters. 
The kinematics equations of the robot are used in robotics, computer games, and animation. The reverse 
process that computes the joint parameters that achieve a specified position of the end-effector is known 
as inverse kinematics. This program is for 2D forward Kinematics and uses the formulas 

 xf = xi + length *cos(angle) 
 yf = yi + length*sin(angle) 
where the angle here is between the x-axis and the segment 
xf and yf are the coordinates of the end point 
xi and yi are the coordinates of the initial point 

Degree of freedom is defined as the minimum number of independent variables required to define the 
position or motion of a system is known as degree of freedom. Degree of freedom is the property of 
kinematic chain which shows that in how many directions the connected links of the kinematic can move 
freely. It is also known by mobility. 
DOF = 3 – Restraint 

To determine DOF of 2-D planar mechanism, Kutzback was a scientist who gave the relation 

DOF = 3(L-1) – 2j – h 
where, 
L = number of links 
j = number of joints 
h = number of higher pairs 

Sometimes a system may have one or more links of a mechanism which do not introduce any extra 
constraint, such links are known as redundant links and should not be counted to find the DOF and also 
corresponding joint will not be counted. 

Sometimes one or more links of a mechanism can be moved without causing any motion to the rest of the 
links of the mechanism, such a link is said to have redundant DOF. Due to this DOF formula for planar 
mechanism is modified. 

DOF = 3(L-1) – 2j – h – Fr 
where, 
Fr = redundant motion

Now Grubler was another scientist, he utilized the Kutzback equation and gave his formulation i.e. he used 
the equation and put DOF equal to 1 and higher pair equal to zero for a kinematic chain. Grubler’s criterion 
was the extension of Kutzback equation and expressed as 

DOF = 3(L-1) – 2j – h 
1 = 3(L-1) – 2j – 0 
3L – 2j – 4 = 0 (this is the derived equation of Grubler’s criterion.) 
From Grubler’s criterion it is clear that to hold the equation number of links should be even i.e. minimum 
number of links required is 4. 

## PROGRAM BUILDING 
This program uses OpenGL to graph the pose. OpenGL Mathematics (GLM) is a C++ mathematics library 
for 3D software based on the OpenGL Shading Language (GLSL) specification.

Works Cited: 
1. https://www.mech4study.com/2018/07/what-is-degree-of-freedom-in-mechanicalengineering.html
2. https://en.wikipedia.org/wiki/Forward_kinematics
3. Mark W. Spong, Seth Hutchinson, and M. Vidyasagar. ‘Robot Modeling and Control’ (First Edition)
4. https://www.opengl.org/sdk/libs/ 

## Input/output Description: 
The inputs are: 
- Start Point or the Base point 
- Angles 
- Lengths 
- User’s option for adding segments along with the angle and length of the segment to be added 
- User’s option for deleting segments and the number of segments to delete 
- User’s option to set to default position or not 
- User’s option to print the pose or not 
- User’s option to get End Effector, if the user wants to calculate the end effector for a new set of angles then, the array of angles will be an input. 

The outputs are: 
- The request to enter the start point, angles and lengths 
- Printing the segment array information 
- The request to whether add any segment or not 
- Printing the new segment array information (includes the added segment info) 
- The request to whether delete any segment or not 
- Printing the new segment array information (after deleting) 
- The request to whether set to default position or not 
- Printing the segment array information after setting to default position 
- The request to whether print the pose or not 
- Printing the pose 
- The request to calculate the End Effector 
- End Effector
