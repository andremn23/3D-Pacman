#include <GL/glut.h>
#include "Floor.h"
#include "glbmp.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL\glut.h>
#include <windows.h>
#include "glbmp.h"

int i = 0;
GLuint texname;
GLuint txParticle;

//Funçao que faz o load da imagem bitmap
void LoadTexture(const char * bitmap_file)
{
		glbmp_t bitmap;     

		if(!glbmp_LoadBitmap(bitmap_file, 0, &bitmap))
		{
			fprintf(stderr, "Error loading bitmap file: %s\n", bitmap_file);
			exit(1);
		}
	glBindTexture(GL_TEXTURE_2D, texname);
	glGenTextures(1, &texname);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmap.width, bitmap.height,
				 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap.rgb_data);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //Para textura a reagir a iluminação: GL_MODULATE, sem: GL_DECAL
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glbmp_FreeBitmap(&bitmap);
}

//Faz o load da imagem de textura
void iniTexture(void)
{
 glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
 LoadTexture("t4.bmp");//Há mais texturas para escolher na pasta
 i= 1;
}

void Floor::draw() {
	
	GLfloat ambientMaterial[]  = { 0.8f,0.8f, 0.8f, 1.0f };
	GLfloat diffuseMaterial[]	= { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat especularMaterial[] = { 0.8f,0.8f,0.8f, 1.0f };
	GLfloat SHININESS = 110;

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especularMaterial);
		glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, SHININESS);

		if (i == 0){ //Condiçao para entrar no iniTextur apenas umas vez
			iniTexture();}
		
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
			glTexCoord2d(_x1,_y1 - 2);		glVertex3f(_x1,_y1 - 2, 0);	
			glTexCoord2d(_x1,_y1);		    glVertex3f(_x1,_y1, 0);	
			glTexCoord2d(_x2,_y2 + 2);      glVertex3f(_x2,_y2 + 2, 0);	
			glTexCoord2d(_x2,_y2);          glVertex3f(_x2,_y2, 0);	
		 glEnd();
		 glPopMatrix();
			
	}
