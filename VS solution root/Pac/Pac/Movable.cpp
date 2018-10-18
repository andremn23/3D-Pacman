#include <iostream>
#include "Movable.h"
#include "AuxFuncs.h"
	
void Movable::draweyes(bool mode){
	GLfloat _red;
	GLfloat _green;
	GLfloat _blue;

	glPushMatrix();
	glTranslatef(0.17,0.2,0.37);
	if(mode){
		_red = 1;
		_green = 1;
		_blue = 1;
	}
	else {
		_red = 0;
		_green = 0;
		_blue = 0;
	}
	GLfloat ambientMaterial[]  = { _red, _green,_blue, 1.0f };
	GLfloat diffuseMaterial[]	= { _red, _green,_blue, 1.0f };
	GLfloat especularMaterial[] = { 0,0,0, 1.0f };
	GLfloat SHININESS = 20;
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	glutSolidSphere(.1,32,32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.17,0.2,0.37);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	glutSolidSphere(.1,32,32);
	glPopMatrix();
}

void Movable::drawiris(bool mode){
	GLfloat _red;
	GLfloat _green;
	GLfloat _blue;

	glPushMatrix();
	glTranslatef(0.177,0.175,0.46);
	if(mode){
		_red = 0;
		_green = 0;
		_blue = 0;
	}
	else {
		_red = 1;
		_green = 1;
		_blue = 1;
	}
	GLfloat ambientMaterial[]  = { _red, _green,_blue, 1.0f };
	GLfloat diffuseMaterial[]	= { _red, _green,_blue, 1.0f };
	GLfloat especularMaterial[] = { 0,0,0, 1.0f };
	GLfloat SHININESS = 20;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	glutSolidSphere(.03,32,32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.177,0.175,0.46);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	glutSolidSphere(.03,32,32);
	glPopMatrix();
}

void Movable::draweyebrows(void){
	GLfloat _red = 0;
	GLfloat _green = 0;
	GLfloat _blue = 0;

	GLfloat ambientMaterial[]  = { _red, _green,_blue, 1.0f };
	GLfloat diffuseMaterial[]	= { _red, _green,_blue, 1.0f };
	GLfloat especularMaterial[] = { 0,0,0, 1.0f };
	GLfloat SHININESS = 20;

	_red = 0;
	_green = 0;
	_blue = 0;

	glPushMatrix();
	glTranslatef(0.13,0.35,0.24);
	glRotatef(20,0,0,1);
	glScalef(1,0.1,1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	glutSolidSphere(0.15,32,32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.13,0.35,0.24);
	glRotatef(-20,0,0,1);
	glScalef(1,0.1,1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
	glutSolidSphere(0.15,32,32);
	glPopMatrix();
}

int Movable::move(double step) {
	float tempX;
	float tempY;
	int coordenadaX;
	int coordenadaY;

	//*************************	
	// Move o pacman para a esquerda (movimento inicial)
	//**************************
	
	if(_direction.compare("left") == 0){
		tempX = adjust(_x);
		tempY = adjust(_y);
		coordenadaX = convertePacX(tempX, tempY);
		coordenadaY = convertePacY(tempX, tempY);
		_dirBeforeStop.replace(0,_dirBeforeStop.length(),_direction);

		if (path[coordenadaX][coordenadaY] == 4){
			_x += step;
		}
		else if (path[coordenadaX][coordenadaY] == 5){
				_x = 13.5;
		}
		else{
			_x -= step;
		}

		// Verifica se a tecla UP foi premida
		if (_turn.compare("up") == 0){
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY) -1;
			coordenadaY = convertePacY(tempX, tempY);
			
			if (casaDecimal(_x) == 5 && path[coordenadaX][coordenadaY] == 1){
				setDirection("up");
			}
			else {
				setDirection("left");
			} 
		}

		// Verifica se a tecla DOWN foi premida
		else if(_turn.compare("down") == 0) {
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY) +1;
			coordenadaY = convertePacY(tempX, tempY);
			
			if (casaDecimal(_x) == 5 && path[coordenadaX][coordenadaY] == 1){
				setDirection("down");
			}				
			else { 
			setDirection("left");	
			} 
		}

		// Verifica se a tecla RIGTH foi premida
		else if(_turn.compare("right") == 0){
   			setDirection("right");
		}

		// Nenhuma tecla premida, então continua o movimento	
		else {
			if(!isWall(_x-step,_y))
				setDirection("left");		
			else setDirection("stopped");
		}
	return 1;
}
		
	//*****************************	
	// Move o pacman para a direita
	//*****************************

	if(_direction.compare("right") == 0){
		tempX = adjust(_x);
		tempY = adjust(_y);
		coordenadaX = convertePacX(tempX, tempY);
		coordenadaY = convertePacY(tempX, tempY) +1;
		_dirBeforeStop.replace(0,_dirBeforeStop.length(),_direction);
   
		if (path[coordenadaX][coordenadaY] == 4){
		//_x += step;
		}else if (path[coordenadaX][coordenadaY] == 5){
							_x = -13.5;
		}
		else{
			_x += step;
		}
		// Verifica se tecla UP foi premida
		if (_turn.compare("up") == 0){
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY)-1;
			coordenadaY = convertePacY(tempX, tempY);
		//	printf ("\nX: %f  Y: %f  CoordX: %d  CoordY: %d  path: ", tempX, tempY, coordenadaX, coordenadaY);
			if (casaDecimal(_x) == 5 && path[coordenadaX][coordenadaY] == 1){
				setDirection("up");
			}		
			else { 
				setDirection("right");	
			}
		}
		else if(_turn.compare("down") == 0) {
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY)+1;
			coordenadaY = convertePacY(tempX, tempY);
			if (casaDecimal(_x) == 5 && path[coordenadaX][coordenadaY] == 1){
				setDirection("down");
			}
			else { 
				setDirection("right");	
			} 
		}
		else if(_turn.compare("left") == 0){
			setDirection("left");
		}
		else {
			if(!isWall(_x+step,_y))
				setDirection("right");		
			else setDirection("stopped");
		}
	return 1;	
	}

	//*************************	
	// Move o pacman para cima
	//*************************

	if(_direction.compare("up") == 0){
		tempX = adjust(_x);
		tempY = adjust(_y);
		coordenadaX = convertePacX(tempX, tempY);
		coordenadaY = convertePacY(tempX, tempY);
		_dirBeforeStop.replace(0,_dirBeforeStop.length(),_direction);
   
		if(casaDecimal(_x) != 5) {
			_x += step;
		}
		else if (path[coordenadaX][coordenadaY] == 4){
			_y -= step;
			}
			else{
				_y += step;
			}
		// Verifica se alguma tecla foi premida
		if (_turn.compare("left") == 0){
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY);
			coordenadaY = convertePacY(tempX, tempY) -1;
			if (casaDecimal(_y) == 0 && path[coordenadaX][coordenadaY] == 1){
				setDirection("left");
			}		
			else { 
				setDirection("up");	
			} 
		}
		else if(_turn.compare("down") == 0) {
			setDirection("down");
		}
		else if(_turn.compare("right") == 0){
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY);
			coordenadaY = convertePacY(tempX, tempY) +1;
			if (casaDecimal(_y) == 0 && path[coordenadaX][coordenadaY] == 1){
				setDirection("right");
			}		
			else { 
				setDirection("up");	
			} 
		}
		else {
			if(!isWall(_x,_y+step))
				setDirection("up");		
			else setDirection("stopped");
		}
	return 1;
	}	

	//*************************	
	// Move o pacman para baixo
	//**************************

	if(_direction.compare("down") == 0){
		tempX = adjust(_x);
		tempY = adjust(_y);
		coordenadaX = convertePacX(tempX, tempY)+1;
		coordenadaY = convertePacY(tempX, tempY);
		_dirBeforeStop.replace(0,_dirBeforeStop.length(),_direction);

		if(casaDecimal(_x) != 5) {
			_x += step;
		} 
	
		else if (path[coordenadaX][coordenadaY] == 4){
		//_y -= step; 
			}
			else{
				_y -= step;
			}
		// Verifica se alguma tecla foi premida
		if (_turn.compare("left") == 0){
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY);
			coordenadaY = convertePacY(tempX, tempY) -1;
			if (casaDecimal(_y) == 0 && path[coordenadaX][coordenadaY] == 1){
				setDirection("left");
			}
			else { 
				setDirection("down");	
			} 
		}
		else if(_turn.compare("up") == 0) {			
			setDirection("up");
		}
		else if(_turn.compare("right") == 0){
			tempX = adjust(_x);
			tempY = adjust(_y);
			coordenadaX = convertePacX(tempX, tempY);
			coordenadaY = convertePacY(tempX, tempY) +1;
			if (casaDecimal(_y) == 0 && path[coordenadaX][coordenadaY] == 1){
				setDirection("right");
			}	
			else { 
				setDirection("down");	
			} 
		}
		else {
			if(!isWall(_x,_y-step))
				setDirection("down");		
			else setDirection("stopped");	
		}
	return 1;	
	}
	if(_direction.compare("stopped") == 0){
		if(_turn.compare(_dirBeforeStop) != 0) {
			// Verifica se a tecla UP foi premida
			if (_turn.compare("up") == 0){
				if(!isWall(_x,_y+1))
					setDirection("up");		
				else setDirection("stopped");
			}		
			// Verifica se a tecla DOWN foi premida
			else if(_turn.compare("down") == 0) {
				if(!isWall(_x,_y-1))
					setDirection("down");		
				else setDirection("stopped");
			}		
			// Verifica se a tecla RIGHT foi premida
			else if(_turn.compare("right") == 0){
				if(!isWall(_x+1,_y))
					setDirection("right");		
				else setDirection("stopped");
			}
			else if(_turn.compare("left") == 0){
    			if(!isWall(_x-1,_y))
					setDirection("left");		
				else setDirection("stopped");
			}	
		}
	}
	return 1;
}