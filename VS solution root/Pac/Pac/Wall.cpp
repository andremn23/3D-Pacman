#include <GL/glut.h>
#include "Wall.h"



void Wall::draw(){
		glDisable(GL_TEXTURE_2D);
		GLfloat ambientMaterial[]  = { 1, 1, 1, 1.0f };
		GLfloat diffuseMaterial[]	= { 1, 1, 1, 1.0f };
		GLfloat especularMaterial[] = { 1,1,1, 1.0f };
		GLfloat SHININESS = 50;

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
		glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);

		glPushMatrix();
		glTranslatef(_tX,_tY,0.1875);
		glScalef(_sX,_sY,0.375);
		glutSolidCube(1);
		glPopMatrix();
}