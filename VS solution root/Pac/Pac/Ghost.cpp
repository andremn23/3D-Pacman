#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "AuxFuncs.h"
#include "Ghost.h"


void Ghost::draw(void){

	GLfloat ambientMaterial[]  = { _r, _g,_b, 1.0f };
	GLfloat diffuseMaterial[]	= { _r, _g,_b, 1.0f };
	GLfloat especularMaterial[] = { 0,0,0, 1.0f };
	GLfloat SHININESS = 20;

	int i;
	double angle;
	GLfloat x1 = 0;
	GLfloat y1 = 0;
	double *x = new double[33];
	double *z = new double[33];
	double *top2X = new double[33];
	double *top2Y = new double[33];

	glPushMatrix();
	glTranslatef(_x,_y,0.5);
	glScalef(1.5,1.5,1.5);
	glRotatef(_eyeAngle,0,0,1);
	glRotatef(90,1,0,0);
	if(_scared){
	GLfloat ambientMaterial[]  = { 1,1,1, 1.0f };
	GLfloat diffuseMaterial[]	= { 1,1,1, 1.0f };
	GLfloat especularMaterial[] = { 0,0,0, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	}
	else{
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	}
 
	//get the x and z position on a circle for all the sides
	for(i=0; i < 33; i++){
		angle = 2*3.1415926535897 / (32) * i;
		x[i] = sin(angle) * 0.5;
		z[i] = cos(angle) * 0.5;
		top2X[i] = sin(angle) * 0.2;
		top2Y[i] = cos(angle) * 0.2;
	}
	//
	//draw the top of the cylinder
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0,0.1,0);
	glVertex3f(0,0.1,0);

	for(i=0; i < 33; i++){
		glNormal3f(x[i],0.1,z[i]);
		glVertex3f(x[i],0.1,z[i]);
	}
 
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0,0.35,0);
	glVertex3f(0,0.35,0);
 
	for(i=0; i < 33; i++){
		glNormal3f(top2X[i],0.35,top2Y[i]);
		glVertex3f(top2X[i],0.35,top2Y[i]);
	}
 
	glEnd();
	//	
    //draw the center of the cylinder
    glBegin(GL_QUAD_STRIP); 
	
    for(i=0; i < 33; i++){
		glNormal3f(x[i],-0.5,z[i]);
		glVertex3f(x[i],-0.5,z[i]);
		glNormal3f(x[i],0.1,z[i]);
		glVertex3f(x[i],0.1,z[i]);
	}
 
	glEnd();
	if(!_scared){
		glColor3f(0,0,0);
	GLfloat ambientMaterial[]  = { 0,0,0, 1.0f };
	GLfloat diffuseMaterial[]	= { 0,0,0, 1.0f };
	GLfloat especularMaterial[] = { 0,0,0, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	}
	glBegin(GL_QUAD_STRIP); 
	
    for(i=0; i < 33; i++){
		glNormal3f(x[i],0.1,z[i]);
		glVertex3f(x[i],0.1,z[i]);
		glNormal3f(top2X[i],0.35,top2Y[i]);
		glVertex3f(top2X[i],0.35,top2Y[i]);
	}
	//
	glEnd();
	if(!_scared)
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	//draw the bottom of the cylinder
	glBegin(GL_TRIANGLE_FAN); 
 
	glNormal3f(0,-0.5,0);
	glVertex3f(0,-0.5,0);
 
	for(i=0; i < 33; i++){
		glNormal3f(x[i],-0.5,z[i]);
		glVertex3f(x[i],-0.5,z[i]);
	}
 
	glEnd();
	//
	drawFace();
	glPopMatrix();
}

void Ghost::drawFace(void){
	if(_scared){
		draweyes(false);
		drawiris(false);
	}
	else{
		draweyes(true);
		drawiris(true);
	}
}

void Ghost::eyeAngle(double pacX, double pacY){
	double x;
	double y;
	double m;
	double angle;
	x = (double) pacX - _x;
	y = (double) pacY - _y;
	m = (double) y/x;
	angle = atan(m);
	if( _x - pacX <= 0)
		_eyeAngle = angle*180/3.14 + 90;
	else _eyeAngle = angle*180/3.14 - 90;
}

bool Ghost::moveAway(){
	if(isScared()){
		if(getRand() <= 75)
			return true;
		return false;
	}	
	else {
		if(getRand() <= 75)
			return false;
		return true;
	}
}

void Ghost::moveOnCage(double step){
	if(!_free){
		if(adjust(_x) >= 1.5){
			setDirection("left");
			setTurn("left");
		}
		if(adjust(_x) <= -1.5){
			setDirection("right");
			setTurn("right");
		}
	}
	else{
		if(adjust(_x) == 1.5){
			setDirection("left");
			setTurn("left");
		}
		if(adjust(_x) == -1.5){
			setDirection("right");
			setTurn("right");
		}
		if(adjust(_x) == 0){
			_y += step;
			setTurn("");
			setDirection("stopped");
		}
		if(adjust(_y) == 3)
			_caged = false;
	}
}

void Ghost::nextTurn(double step){	
	//std::cout << _eyeAngle << "  direcção:" << _direction << _turn << std::endl;

	//Senão estiver parado
	if(_direction.compare("up") == 0){
		if(isWall(_x,_y+step))
			setDirection("stopped");
		else{
			if((_eyeAngle >= 135 && _eyeAngle <= 180) || (_eyeAngle <= -135 && _eyeAngle >= -180)){
				if(!isWall(_x,_y+1)){
					if(!moveAway())
						_turn.replace(0,_turn.length(),"up");
					else if(_eyeAngle > 0 && _eyeAngle <= 180){
						if(!isWall(_x-step,_y))
							_turn.replace(0,_turn.length(),"left");
					}
					else if(!isWall(_x+step,_y))
						_turn.replace(0,_turn.length(),"right");
				}
			}
			else if(_eyeAngle > 0 && _eyeAngle <= 135){
				if(!isWall(_x+step,_y))
					if(!moveAway())
						_turn.replace(0,_turn.length(),"right");
					else if(!isWall(_x-step,_y))
						_turn.replace(0,_turn.length(),"left");
			}
			else if(_eyeAngle < 0 && _eyeAngle >= -135){
				if(!isWall(_x-step,_y))
					if(!moveAway())
						_turn.replace(0,_turn.length(),"left");
					else if(!isWall(_x+step,_y))
						_turn.replace(0,_turn.length(),"right");
			}
		}
	}

	if(_direction.compare("down") == 0){
		if(isWall(_x,_y-1))
			setDirection("stopped");
		else{
			if((_eyeAngle >= -45 && _eyeAngle <= 0) || (_eyeAngle <= 45 && _eyeAngle >= 0)){
				if(!isWall(_x,_y-step)){
					if(!moveAway())
						_turn.replace(0,_turn.length(),"down");
					else if(_eyeAngle > 0 && _eyeAngle <= 180){
						if(!isWall(_x-step,_y))
							_turn.replace(0,_turn.length(),"left");
					}
					else if(!isWall(_x+step,_y))
						_turn.replace(0,_turn.length(),"right");
				}
			}
			else if(_eyeAngle > 45 && _eyeAngle <= 180){
				if(!isWall(_x+step,_y))
					if(!moveAway())
						_turn.replace(0,_turn.length(),"right");
					else if(!isWall(_x-step,_y))
						_turn.replace(0,_turn.length(),"left");
			}	
			else if(_eyeAngle < -45 && _eyeAngle >= -180){
				if(!isWall(_x-step,_y))
					if(!moveAway())
						_turn.replace(0,_turn.length(),"left");
					else if(!isWall(_x+step,_y))
						_turn.replace(0,_turn.length(),"right");
			}
		}
	}
	if(_direction.compare("left") == 0){
		if(isWall(_x-step,_y)){
			setDirection("stopped");
		}
		else {
			if(_eyeAngle <= -45 && _eyeAngle >= -135){
				if(!isWall(_x-step,_y)){
					if(!moveAway())
						_turn.replace(0,_turn.length(),"left");
					else if((_eyeAngle >= -180 && _eyeAngle <= -90) || (_eyeAngle >= 90 && _eyeAngle <= 180)){
						if(!isWall(_x,_y-step))
							_turn.replace(0,_turn.length(),"down");
					}
					else if(!isWall(_x,_y+step))
						_turn.replace(0,_turn.length(),"up");
				}
			}
			else if((_eyeAngle <= -135 && _eyeAngle >= -180) || (_eyeAngle <= 180 && _eyeAngle >= 90)){
				if(!isWall(_x,_y+step))
					if(!moveAway())
						_turn.replace(0,_turn.length(),"up");
					else if(!isWall(_x,_y-step))
						_turn.replace(0,_turn.length(),"down");
			}
			else if((_eyeAngle <= 0 && _eyeAngle >= -45) || (_eyeAngle <= 90 && _eyeAngle >= 0)){
				if(!isWall(_x,_y-step))
					_turn.replace(0,_turn.length(),"down");
				else if(!isWall(_x,_y+step))
						_turn.replace(0,_turn.length(),"up");
			}
		}
	}
	if(_direction.compare("right") == 0){
		if(isWall(_x+1,_y))
			setDirection("stopped");
		else {
			if(_eyeAngle <= 135 && _eyeAngle >= 45){
				if(!isWall(_x+step,_y)){
					if(!moveAway())
						_turn.replace(0,_turn.length(),"right");
					else if((_eyeAngle >= -180 && _eyeAngle <= -90) || (_eyeAngle >= 90 && _eyeAngle <= 180)){
						if(!isWall(_x,_y-step))
							_turn.replace(0,_turn.length(),"down");
					}
					else if(!isWall(_x,_y+step))
						_turn.replace(0,_turn.length(),"up");
				}
			}
			else if((_eyeAngle <= 180 && _eyeAngle >= 135) || (_eyeAngle <= -90 && _eyeAngle >= -180)){
				if(!isWall(_x,_y+step))
					if(!moveAway())
						_turn.replace(0,_turn.length(),"up");
					else if(!isWall(_x,_y-step))
						_turn.replace(0,_turn.length(),"down");
			}
			else if((_eyeAngle <= 45 && _eyeAngle >= 0) || (_eyeAngle <= 0 && _eyeAngle >= -90)){
				if(!isWall(_x,_y-step))
					if(!moveAway())
						_turn.replace(0,_turn.length(),"down");
					else if(!isWall(_x,_y+step))
						_turn.replace(0,_turn.length(),"up");
			}
		}
	}

	if(_direction.compare("stopped") == 0){
		
		if(_dirBeforeStop.compare("up") == 0){
			if(!moveAway()){
				if(_eyeAngle >= 90 && _eyeAngle <= 180){
					if(!isWall(_x+1,_y))
						_turn.replace(0,_turn.length(),"right");
					else {
						if(!isWall(_x-1,_y))
							_turn.replace(0,_turn.length(),"left");
						else _turn.replace(0,_turn.length(),"down");
					}
				}
				else if(_eyeAngle <= -90 && _eyeAngle >= -180){
					if(!isWall(_x-1,_y))
						_turn.replace(0,_turn.length(),"left");
					else {
						if(!isWall(_x+1,_y))
							_turn.replace(0,_turn.length(),"right");
						else _turn.replace(0,_turn.length(),"down");
					}
				}
				else _turn.replace(0,_turn.length(),"down");
			}
			else _turn.replace(0,_turn.length(),"down");
		}

		if(_dirBeforeStop.compare("down") == 0){
			if(!moveAway()){
				if(_eyeAngle >= 0 && _eyeAngle <= 90){
					if(!isWall(_x+1,_y))
						_turn.replace(0,_turn.length(),"right");
					else {
						if(!isWall(_x-1,_y))
							_turn.replace(0,_turn.length(),"left");
					}
				}
				else if(_eyeAngle <= 0 && _eyeAngle >= -90){
					if(!isWall(_x-1,_y))
						_turn.replace(0,_turn.length(),"left");
					else {
						if(!isWall(_x+1,_y))
							_turn.replace(0,_turn.length(),"right");
					}
				}
				else _turn.replace(0,_turn.length(),"up");
			}
			else _turn.replace(0,_turn.length(),"up");
		}

		if(_dirBeforeStop.compare("right") == 0){
			if(!moveAway()){
				if(_eyeAngle >= 90 && _eyeAngle <= 180){
					if(!isWall(_x,_y+1))
						_turn.replace(0,_turn.length(),"up");
					else {
						if(!isWall(_x,_y-1))
							_turn.replace(0,_turn.length(),"down");
						else _turn.replace(0,_turn.length(),"left");
					}
				}
				else if(_eyeAngle >= 0 && _eyeAngle <= 90){
					if(!isWall(_x,_y-1))
						_turn.replace(0,_turn.length(),"down");
					else {
						if(!isWall(_x,_y+1))
							_turn.replace(0,_turn.length(),"up");
						else _turn.replace(0,_turn.length(),"left");
					}
				}
				else _turn.replace(0,_turn.length(),"left");
			}
			else _turn.replace(0,_turn.length(),"left");
		}

		if(_dirBeforeStop.compare("left") == 0){
			if(!moveAway()){
				if(_eyeAngle >= -180 && _eyeAngle <= -90){
					if(!isWall(_x,_y+1))
						_turn.replace(0,_turn.length(),"up");
					else {
						if(!isWall(_x,_y-1))
							_turn.replace(0,_turn.length(),"down");
						else _turn.replace(0,_turn.length(),"right");
					}
				}
				else if(_eyeAngle >= -90 && _eyeAngle <= 0){
					if(!isWall(_x,_y-1))
						_turn.replace(0,_turn.length(),"down");
					else {
						if(!isWall(_x,_y+1))
							_turn.replace(0,_turn.length(),"up");
						else _turn.replace(0,_turn.length(),"right");
					}
				}
				else _turn.replace(0,_turn.length(),"right");
			}
			else _turn.replace(0,_turn.length(),"right");
		}
	}
}
