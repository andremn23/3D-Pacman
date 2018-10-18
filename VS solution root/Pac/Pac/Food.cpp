#include <GL/glut.h>
#include "Food.h"
void Food::draw(){
	/*	GLfloat r1 = 0;
		GLfloat g1 = 0;
		GLfloat b1 = 0;

	if( _s == 0.2){
		r1 = 0.2;
		g1 = 0.2;
		b1 = 0.2;
	}

	else{
		r1 = 0.7;
		g1 = 0.7;
		b1 = 0.7;
	}*/
	
	
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(_tX,_tY,0.6);
	glScalef(_s,_s,_s);
	if( _s == 0.2f){
	GLfloat ambientMaterial[]  = { 0.6f,0.6f,0.6f, 1.0f };
	GLfloat diffuseMaterial[]	= {0.9,0.9f,0.9f, 1.0f };
	GLfloat especularMaterial[] = { 1,1,1, 1.0f };
	GLint SHININESS = 127;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especularMaterial);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, SHININESS);
	}
	else{
	GLfloat ambientMaterialg[]  = { 1.0f,0.4,0.0f, 1.0f };
	GLfloat diffuseMaterialg[]	= {1.0f,0.4,0.0f, 1.0f };
	GLfloat especularMaterialg[] = { 1,1,1, 1.0f };
	GLint SHININESSg = 127;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterialg);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterialg);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especularMaterialg);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, SHININESSg);
	}
	glutSolidSphere(0.6, 20, 20);
	glPopMatrix();
}

float Food::getPacX(){
	return _tX;
}

float Food::getPacY(){
	return _tY;

}