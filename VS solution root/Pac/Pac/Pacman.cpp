#include <GL/glut.h>
#include "pacman.h"
#include "AuxFuncs.h"

void Pacman::draw(void){
	GLfloat r = 1;
	GLfloat g = 0.7;
	GLfloat b = 0;
	GLfloat SHININESS;
	if(_divineIntervention){
		r = 0.5;
		g = 0.6;
		b = 0.3;
		SHININESS = 160;
	}
	else{
		r = 1;
		g = 0.7;
		b = 0;
		SHININESS = 60;
	}
	GLfloat ambientMaterial[]  = { r, g, b, 1.0f };
	GLfloat diffuseMaterial[]	= { r, g, b, 1.0f };
	GLfloat especularMaterial[] = { 0.6,0.6,0.6, 1.0f };
	

		

	glPushMatrix();
	glTranslatef(_x,_y,0.75);
	glScalef(1.5,1.5,1.5);
	glRotatef(_rotate,0,0,1);
	glRotatef(90,1,0,0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especularMaterial);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, SHININESS);
	glutSolidSphere(0.5,32,32);
	drawFace();
	glPopMatrix();
}

void Pacman::drawFace(void){
	if(_direction.compare("up") == 0)
		_rotate = 180;
	if(_direction.compare("right") == 0)
		_rotate = 90;
	if(_direction.compare("down") == 0)
		_rotate = 0;
	if(_direction.compare("left") == 0)
		_rotate = -90;
	draweyes(true);
	drawiris(true);
	draweyebrows();
}

