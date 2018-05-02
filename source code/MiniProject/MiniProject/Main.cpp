/*  
    
    OpenGL Mini-Project
  
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "legobrick.h"
#include "floor.h"
#include "shadow.h"
#include "legoHouse.h"

#include "glut.h"
#include "gsrc.h" // Include the header file of our rotation user-interface.

#define PI			3.141592654  // Prime
#define WIN_POSX    400
#define WIN_POSY    400
#define WIN_WIDTH   400
#define WIN_HEIGHT  300

GLdouble t;		// elapsed time
double t_prev;	// previous time elapsed
int height = 0;	// hight of lego house

// colors
GLfloat redColor[] = {1.0,0.0,0.0};
GLfloat whiteColor[] = {1.0,1.0,1.0};
GLfloat blackColor[] = {0.0,0.0,0.0};

void drawscene (void)     
{
	// Setup perspective projection and the rotation 
    GLint viewport[4];
    glGetIntegerv( GL_VIEWPORT, viewport ); // viewport is by default the display window
    glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective( 45, double(viewport[2])/viewport[3], 0.1, 1000 );
    glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      gluLookAt( 0.0, 200.0, 400, 0, 100, 0, 0,1,0 );
      glMultMatrixf( gsrc_getmo() );  // get the rotation matrix from the rotation user-interface
	  

	/*  Enable Z buffer method for visibility determination. */	
	glClear (GL_DEPTH_BUFFER_BIT);
	glEnable (GL_DEPTH_TEST);	

	//display window color
	glClearColor (1.0, 1.0, 1.0, 0.0);	// Set display-window color to white.
	glClear (GL_COLOR_BUFFER_BIT);		// Clear display window.
	
	// light
	glEnable(GL_LIGHTING);
	GLfloat light1PosType [ ] = {-50, 100, 50, 1.0};	// Light source position
	glLightfv(GL_LIGHT0, GL_POSITION, light1PosType);
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor); 
	glEnable(GL_LIGHT0);
		

	glPushMatrix();
	glScalef(2.0, 2.0, 2.0);
	build_lego_house(height, t, t_prev);
	glPopMatrix();

	draw_floor();

	glutSwapBuffers();
}

void animate(void)
{
	t = glutGet(GLUT_ELAPSED_TIME);

	glutPostRedisplay();
}

void selection (GLubyte key, GLint xMouse, GLint yMouse)
{
        switch (key) {
		case '1':		
			height = 1;
			t_prev = glutGet (GLUT_ELAPSED_TIME); 
			break;
		case '2':		
			height = 2;
			t_prev = glutGet (GLUT_ELAPSED_TIME); 
			break;
		case '3':		
			height = 3;
			t_prev = glutGet (GLUT_ELAPSED_TIME); 
			break;
		case '4':		
			height = 4;
			t_prev = glutGet (GLUT_ELAPSED_TIME); 
			break;
		case '5':		
			height = 5;
			t_prev = glutGet (GLUT_ELAPSED_TIME); 
			break;
		case '6':		
			height = 6;
			t_prev = glutGet (GLUT_ELAPSED_TIME); 
			break;
		
		default:		
			printf ("\nNot a good hight! \nIf you want a cool house, \nplease choose a valid height!");
			break;
		}

		glutPostRedisplay ( );                   // redisplay the modified object	
}


void main (int argc, char** argv)
{
     
		glutInit (&argc, argv);			                      // Initialize GLUT
		glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB |  GLUT_DEPTH); // Set display mode
		
		glutInitWindowPosition( WIN_POSX, WIN_POSY );         // Set display-window position at (WIN_POSX, WIN_POSY) 
                                                              // where (0, 0) is top left corner of monitor screen
        glutInitWindowSize( WIN_WIDTH, WIN_HEIGHT );		  // Set display-window width and height.

		glutCreateWindow ("LEGO House" );					  // Create display window.

		printf ("Welcome to the LEGO house building project! \n"); 
		printf ("You get to choose the height of this amazing brick house. \n");
		printf ("To set the hight enter a number from 1 to 6. \n");

		glutKeyboardFunc (selection);
		glutIdleFunc(animate);

		//////////////////////////////////////////////////////////////////
	    // 
		// Register mouse-click and mouse-move glut callback functions
		// for the rotation user-interface.
		// 
		glutMouseFunc( gsrc_mousebutton );
		glutMotionFunc( gsrc_mousemove );
		//
		//////////////////////////////////////////////////////////////////
		
        glutDisplayFunc (drawscene);   // put everything you wish to draw in drawscene

		glutMainLoop ( );
	
}