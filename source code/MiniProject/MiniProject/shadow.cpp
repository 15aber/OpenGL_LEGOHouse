#include "shadow.h"
#include "legobrick.h"
#include "glut.h"

void generate_shadow(double x, double y, double z, double theta, double rotX, double rotY, double rotZ)
{
	//material properties
	GLfloat diffuseCoeff[] = {0.0,0.0,0.0,1.0};
	GLfloat specularCoeff[] = {0.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffuseCoeff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularCoeff);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
	glShadeModel(GL_SMOOTH);
	GLfloat surfEmissionBlack[] = {0.0,0.0,0.0};
	glMaterialfv(GL_FRONT, GL_EMISSION, surfEmissionBlack);

	GLfloat  M[16];

	for (int i=0; i<16; i++)     
		M[i] = 0;  

	M[0]=M[5]=M[10]=1.0; 
	M[7]=-1/(100.0 - 0.1);	//array index 7 since shadow should be projected on the z-x plane

	glPushMatrix ( ); // save state  
	glMatrixMode (GL_MODELVIEW);
	glTranslatef (-50, 100, 50); // M_(WC <-- s)
	glMultMatrixf (M); // perspective projection
	glTranslatef (50, -100, -50); // M_(s <-- WC)

	draw_8brick(x, y, z, theta, rotX, rotY, rotZ);
	glPopMatrix ( ); // restore state
}

void generate_shadow_4brick(double x, double y, double z, double theta, double rotX, double rotY, double rotZ)
{
	//material properties
	GLfloat diffuseCoeff[] = {0.0,0.0,0.0,1.0};
	GLfloat specularCoeff[] = {0.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffuseCoeff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularCoeff);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
	glShadeModel(GL_SMOOTH);
	GLfloat surfEmissionBlack[] = {0.0,0.0,0.0};
	glMaterialfv(GL_FRONT, GL_EMISSION, surfEmissionBlack);

	GLfloat  M[16];

	for (int i=0; i<16; i++)     
		M[i] = 0;  

	M[0]=M[5]=M[10]=1.0; 
	M[7]=-1/(100.0 - 0.1);	//array index 7 since shadow should be projected on the z-x plane

	glPushMatrix ( ); // save state  
	glMatrixMode (GL_MODELVIEW);
	glTranslatef (-50, 100, 50); // M_(WC <-- s)
	glMultMatrixf (M); // perspective projection
	glTranslatef (50, -100, -50); // M_(s <-- WC)

	draw_4brick(x, y, z, theta, rotX, rotY, rotZ);

	glPopMatrix ( ); // restore state
}

void generate_shadow_24brick(double x, double y, double z, double theta, double rotX, double rotY, double rotZ)
{
	//material properties
	GLfloat diffuseCoeff[] = {0.0,0.0,0.0,1.0};
	GLfloat specularCoeff[] = {0.0,0.0,0.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffuseCoeff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularCoeff);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
	glShadeModel(GL_SMOOTH);
	GLfloat surfEmissionBlack[] = {0.0,0.0,0.0};
	glMaterialfv(GL_FRONT, GL_EMISSION, surfEmissionBlack);

	GLfloat  M[16];

	for (int i=0; i<16; i++)     
		M[i] = 0;  

	M[0]=M[5]=M[10]=1.0; 
	M[7]=-1/(100.0 - 0.1);	//array index 7 since shadow should be projected on the z-x plane

	glPushMatrix ( ); // save state  
	glMatrixMode (GL_MODELVIEW);
	glTranslatef (-50, 100, 50); // M_(WC <-- s)
	glMultMatrixf (M); // perspective projection
	glTranslatef (50, -100, -50); // M_(s <-- WC)

	draw_24brick(x, y, z, theta, rotX, rotY, rotZ);
	glPopMatrix ( ); // restore state
}