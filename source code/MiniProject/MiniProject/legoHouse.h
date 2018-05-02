#include "glut.h"

GLfloat* colorRotation(int num);

void buildOddFloor(GLdouble elapsedTime, int floorLevel); //floorLevel == 0 is ground floor

void buildEvenFloor(GLdouble elapsedTime, int floorLevel);

void buildRoof(GLdouble elapsedTime, int floorLevel);

void build_lego_house(int floors, GLdouble elapsedTime, double t_prev);