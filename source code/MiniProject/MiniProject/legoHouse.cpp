#include <math.h>
#include "legoHouse.h"
#include "legobrick.h"
#include "shadow.h"
#include "glut.h"
#include "gsrc.h"

#define PI			3.141592654  // Prime
#define FLOOR_HIGHT	10

GLfloat surfEmissionRed[]		= {1.0,0.0,0.0};
GLfloat surfEmissionGreen[]		= {0.0,1.0,0.0};
GLfloat surfEmissionBlue[]		= {0.0,0.0,1.0};
GLfloat surfEmissionYellow[]	= {1.0,1.0,0.0};
GLfloat surfEmissionPink[]		= {1.0,0.0,1.0};

GLdouble build_time = 10000.0;

//Lego bricks in different colors are cool :D 
GLfloat* colorRotation(int num)
{

	switch (num % 4)
	{
	case 0:
		return surfEmissionRed;
		break;
	case 1:
		return surfEmissionGreen;
		break;
	case 2:
		return surfEmissionBlue;
		break;
	case 3: 
		return surfEmissionYellow;
		break;
	default:
		return surfEmissionPink; //if you get pink, something went wrong
		break;
	}
}

void buildEvenFloor(GLdouble elapsedTime, int floorLevel)
{
	const int numOfBricks = 8;
	double exponent = 0.7;
	GLdouble brick_build_time = build_time/numOfBricks;
	double x_pos[numOfBricks] = {32.0, 40.0, 40.0, 16.0, -16.0, -40.0, -40.0, -32.0};	//x-coordinates of the legobricks
	double y_pos[numOfBricks] = {};													//y-coordinates of the legobricks
	double z_pos[numOfBricks] = {0.0, -24.0, -56.0, -64.0, -64.0, -56.0, -24.0, 0.0};	//z-coordinates of the legobricks
	double rotTheta[numOfBricks] = {0.0, 90.0, 90.0, 0.0, 0.0, 90.0, 90.0, 0.0};

	int brickNum;
	
	//set the y coordinates of the bricks as a function of time, to make them fall; 
	for (brickNum = 0; brickNum < numOfBricks; brickNum++)
	{
		glPushMatrix();
		double timeOffset = (brick_build_time)*(brickNum)+(build_time*(double)floorLevel);
		double timeOffsetNextBrick = (brick_build_time)*(brickNum+1)+(build_time*(double)floorLevel);

		if(elapsedTime < timeOffsetNextBrick && elapsedTime > timeOffset)	// if it is time for the brick to move
		{
			double t = elapsedTime - timeOffset;
			y_pos[brickNum] = ((double)floorLevel * FLOOR_HIGHT) + 400 - 400 * (1 - pow(cos(PI*t/(2*brick_build_time)), exponent)); //accelerate falling lego brick

			//draw brick and shadow
			set_brick_material_properties();
			glMaterialfv(GL_FRONT, GL_EMISSION, colorRotation(brickNum)); //let the bricks be in different colors
			draw_8brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			generate_shadow(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
		}
		else if(elapsedTime >= timeOffsetNextBrick) //if the brick is done moving, draw it at the end position
		{
			y_pos[brickNum] = (double)floorLevel*FLOOR_HIGHT;
			//draw brick and shadow
			set_brick_material_properties();
			glMaterialfv(GL_FRONT, GL_EMISSION, colorRotation(brickNum)); //let the bricks be in different colors
			draw_8brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			generate_shadow(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
		}

				
		glPopMatrix();
	}
}

void buildOddFloor(GLdouble elapsedTime, int floorLevel)
{
	const int numOfBricks = 9;
	double exponent = 0.7;
	GLdouble brick_build_time = build_time/numOfBricks;
	double x_pos[numOfBricks] = {24.0, 40.0, 40.0, 32.0, 0.0, -32.0, -40.0, -40.0, -24.0};	//x-coordinates of the legobricks
	double y_pos[numOfBricks] = {};													//y-coordinates of the legobricks
	double z_pos[numOfBricks] = {0.0, -8.0, -40.0, -64.0, -64.0, -64.0, -40.0, -8.0, 0.0};	//z-coordinates of the legobricks
	double rotTheta[numOfBricks] = {0.0, 90.0, 90.0, 0.0, 0.0, 0.0, 90.0, 90.0, 0.0};

	int brickNum;
	
	//set the y coordinates of the bricks as a function of time, to make them fall; 
	for (brickNum = 0; brickNum < numOfBricks; brickNum++)
	{
		glPushMatrix();
		double timeOffset = (brick_build_time)*(brickNum)+(build_time*(double)floorLevel);
		double timeOffsetNextBrick = (brick_build_time)*(brickNum+1)+(build_time*(double)floorLevel);

		if(elapsedTime < timeOffsetNextBrick && elapsedTime > timeOffset)	// if it is time for the brick to move
		{
			double t = elapsedTime - timeOffset;
			y_pos[brickNum] = ((double)floorLevel * FLOOR_HIGHT) + 400 - 400 * (1 - pow(cos(PI*t/(2*brick_build_time)), exponent)); //accelerate falling lego brick

			//draw brick and shadow
			set_brick_material_properties();
			glMaterialfv(GL_FRONT, GL_EMISSION, colorRotation(brickNum)); //let the bricks be in different colors
			if(brickNum == 0 || brickNum == 8)	//the first and the last bricks are 4x4
			{
				draw_4brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
				generate_shadow_4brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			}
			else
			{
				draw_8brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
				generate_shadow(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			}
		}
		else if(elapsedTime >= timeOffsetNextBrick) //if the brick is done moving, draw it at the end position
		{
			y_pos[brickNum] = (double)floorLevel*FLOOR_HIGHT;
			//draw brick and shadow
			set_brick_material_properties();
			glMaterialfv(GL_FRONT, GL_EMISSION, colorRotation(brickNum)); //let the bricks be in different colors
			if(brickNum == 0 || brickNum == 8)	//the first and the last bricks are 4x4
			{
				draw_4brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			}
			else //draw 8x8 brick
			{
				draw_8brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
				generate_shadow(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			}			
		}				
		glPopMatrix();
	}
}


void buildRoof(GLdouble elapsedTime, int floorLevel)
{
	const int numOfBricks = 5;
	double exponent = 0.7;
	GLdouble brick_build_time = build_time/numOfBricks;
	double x_pos[numOfBricks] = {0.0, 0.0, 0.0, 0.0, 0.0};			//x-coordinates of the legobricks
	double y_pos[numOfBricks] = {};									//y-coordinates of the legobricks
	double z_pos[numOfBricks] = {0.0, -16.0, -32.0, -48.0, -64.0};	//z-coordinates of the legobricks
	double rotTheta[numOfBricks] = {0.0, 0.0, 0.0, 0.0, 0.0};

	int brickNum;
	
	//set the y coordinates of the bricks as a function of time, to make them fall; 
	for (brickNum = 0; brickNum < numOfBricks; brickNum++)
	{
		glPushMatrix();
		double timeOffset = (brick_build_time)*(brickNum)+(build_time*(double)floorLevel);
		double timeOffsetNextBrick = (brick_build_time)*(brickNum+1)+(build_time*(double)floorLevel);

		if(elapsedTime < timeOffsetNextBrick && elapsedTime > timeOffset)	// if it is time for the brick to move
		{
			double t = elapsedTime - timeOffset;
			y_pos[brickNum] = ((double)floorLevel * FLOOR_HIGHT) + 400 - 400 * (1 - pow(cos(PI*t/(2*brick_build_time)), exponent)); //accelerate falling lego brick

			//draw brick and shadow
			set_brick_material_properties();
			glMaterialfv(GL_FRONT, GL_EMISSION, colorRotation(brickNum)); //let the bricks be in different colors
			draw_24brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			generate_shadow_24brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
		}
		else if(elapsedTime >= timeOffsetNextBrick) //if the brick is done moving, draw it at the end position
		{
			y_pos[brickNum] = (double)floorLevel*FLOOR_HIGHT;
			//draw brick and shadow
			set_brick_material_properties();
			glMaterialfv(GL_FRONT, GL_EMISSION, colorRotation(brickNum)); //let the bricks be in different colors
			draw_24brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
			generate_shadow_24brick(x_pos[brickNum], y_pos[brickNum], z_pos[brickNum], rotTheta[brickNum], 0.0, 1.0, 0.0);
		}				
		glPopMatrix();
	}
}

//Build the lego house with the user-specified height (floors)
//Odd and even floors to interchange the position of the bricks for a solid house
//Always put a roof on the house - don't want rain inside
void build_lego_house(int floors, GLdouble elapsedTime, double t_prev)
{
	//don't draw house of invalid height
	if (floors < 1 || 6 < floors)
		return;

	double elapsedConstructionTime = elapsedTime-t_prev;
	int i;
	for(i = 0; i < (floors-1); i++)
	{
		if(i %2)
		{
			buildOddFloor(elapsedConstructionTime, i);
		}
		else
		{
			buildEvenFloor(elapsedConstructionTime, i);
		}
	}
	buildRoof(elapsedConstructionTime, floors-1);	
}

