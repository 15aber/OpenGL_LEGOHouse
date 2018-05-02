#include "glut.h"
#include <stdio.h>

#define IW			400		// Width of the image
#define IH			400		// Height of the image
char* filename = "texture.bmp"; // Read the texture.bmp image
GLuint texture;
GLubyte InputImage[IW][IH][4];

void read_raw_image(unsigned char Image[][IH][4]) // read the image
{ 
	FILE *fp;
	unsigned char temp;

	if ((fp = fopen(filename, "rb")) == NULL) {
		printf("Error (ReadImage) : Cannot read the file!\n");
		//exit(1);
	}

	for (int i = 0; i < IW; i++) {
		for (int j = 0; j < IH; j++) {
			for (int k = 0; k < 3; k++) {
				fscanf(fp, "%c", &temp);
				Image[i][j][k] = (unsigned char)temp;
			}
			Image[i][j][3] = (unsigned char)0;
		}
	}
	fclose(fp);
}

void draw_floor( void )
{
	read_raw_image(InputImage);

	//material properties
	GLfloat diffuseCoeff[] = {0.3,0.3,0.3,1.0};
	GLfloat specularCoeff[] = {0.1,0.1,0.1,1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffuseCoeff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularCoeff);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1.0);
	glShadeModel(GL_SMOOTH);
	GLfloat surfEmissionGrey[] = {0.6,0.6,0.6};
	glMaterialfv(GL_FRONT, GL_EMISSION, surfEmissionGrey);

	//Texture mapping
	glEnable(GL_TEXTURE_2D);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, IW, IH, 0, GL_RGBA, GL_UNSIGNED_BYTE, InputImage);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-300.0,0.0,-300.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(-300.0,0.0,300.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(300.0,0.0,300.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(300.0,0.0,-300.0);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
}