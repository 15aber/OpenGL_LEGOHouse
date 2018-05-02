#include "legobrick.h"
#include "glut.h"

void cube ( )
// draw a standard 2 x 2 x 2 cube whose center is at (0, 1, 0)
{
    glPushMatrix ( );
	glTranslatef  (0, 1, 0);
	glutSolidCube (2);
    glPopMatrix  ( );
}

void draw_stud(void)
{
	glPushMatrix ( );
				
	GLUquadricObj *pObj1, *pObj2, *pObj3;				
				   
	glRotatef (-90.0, 1.0, 0.0, 0.0);   // rotate about x axis by -90 deg.
	
	//draw cylinder
	pObj1 = gluNewQuadric ( );
	gluCylinder (pObj1, 2.5, 2.5, 2.0, 10, 10);
	// base radius 2.5  
	// top  radius 2.5
	// height 2.0
    // 10 x 10 controls the sampling
	 
	// draw a solid disk to cover the base 
	pObj2 = gluNewQuadric ( );
	gluDisk (pObj2, 0, 2.5, 10, 10);

	// draw a solid disk to cover the top
    glPushMatrix ( );
    glTranslatef (0.0, 0.0, 2.0);
    pObj3 = gluNewQuadric ( );
	gluDisk (pObj3, 0, 2.5, 10, 10);
    glPopMatrix ( );

    glPopMatrix ( );
}

void draw_8brick (double x, double y, double z, double theta, double rotX, double rotY, double rotZ)
{
	//draw
	glPushMatrix ( );
	glTranslatef(x, y, z);
	glRotatef(theta, rotX, rotY, rotZ);

	glPushMatrix ( );			
	glScalef (16.0, 5.0, 8.0);       
	cube ( ); 
	glPopMatrix ( );

	glTranslatef (-12.0, 10, -4.0); //reposition to first stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 2nd stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 3rd stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 4th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 5th stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 6th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 7th stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 8th stud
	draw_stud();

	glPopMatrix ( );
}

void draw_4brick (double x, double y, double z, double theta, double rotX, double rotY, double rotZ)
{
	//draw
	glPushMatrix ( );
	glTranslatef(x, y, z);
	glRotatef(theta, rotX, rotY, rotZ);

	glPushMatrix ( );			
	glScalef (8.0, 5.0, 8.0);       
	cube ( ); 
	glPopMatrix ( );

	glTranslatef (-4.0, 10, -4.0); //reposition to first stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 2nd stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 3rd stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 4th stud
	draw_stud();
	
	glPopMatrix ( );
}

void draw_24brick (double x, double y, double z, double theta, double rotX, double rotY, double rotZ)
{
	//draw
	glPushMatrix ( );
	glTranslatef(x, y, z);
	glRotatef(theta, rotX, rotY, rotZ);

	glPushMatrix ( );			
	glScalef (48.0, 5.0, 8.0);       
	cube ( ); 
	glPopMatrix ( );

	glTranslatef (-44.0, 10, -4.0); //reposition to first stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 2nd stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 3rd stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 4th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 5th stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 6th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 7th stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 8th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 9th stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 10th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 11th stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 12th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 13th stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 14th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 15th stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 16th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 17th stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 18th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 19th stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 20th stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 21st stud
	draw_stud();
	glTranslatef (0.0, 0.0, 8.0); //reposition to 22nd stud
	draw_stud();
	glTranslatef (8.0, 0.0, 0.0); //reposition to 23rd stud
	draw_stud();
	glTranslatef (0.0, 0.0, -8.0); //reposition to 24th stud
	draw_stud();

	glPopMatrix ( );
}

void set_brick_material_properties (void)
{
	//brick material properties		
		GLfloat diffuseCoeff[] = {0.9,0.9,0.9,1.0};
		GLfloat specularCoeff[] = {0.9,0.9,0.9,1.0};	
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffuseCoeff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularCoeff);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128.0);
		glShadeModel(GL_SMOOTH);
		GLfloat surfEmissionRed[] = {1.0,0.0,0.0};
		glMaterialfv(GL_FRONT, GL_EMISSION, surfEmissionRed);
}