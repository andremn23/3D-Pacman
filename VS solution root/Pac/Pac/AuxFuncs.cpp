#include <math.h>
#include <string>
#include <time.h>
#include "AuxFuncs.h"


//Funçao que converte a posição x do pacman na respectiva posição da matriz
int convertePacX(float pacX, float pacY){

        int coordenadaX = 0;
      	coordenadaX = 15 - pacY;
     	return coordenadaX;
	}

//Funçao que converte a posição x do pacman na respectiva posição da matriz
int convertePacY(float pacX, float pacY){

        int coordenadaY = 0;
		coordenadaY = 14.5 + pacX;
		return coordenadaY;
	}

//Devolve a casa decimal das variavel pacX ou pacY (para calcular as curvas)
int casaDecimal(float pacx){

int result;
	if (pacx == 0){
		pacx = 10;
		result = (int)pacx;
		return result;
	} else


    if (pacx > 0) {
        while (pacx > 1) {
        pacx -= 1.0;
		}

    pacx = pacx*10;
    result = (int)pacx;
    	return result;
    } else {
		while (pacx < -1) {
		pacx += 1.0;
		}

	pacx = pacx*10;
	pacx = pacx*-1;
	result = (int)pacx;
		return result;
	}
}

float adjust(float x){
   if (x > 0){
    float rounded_down = floorf(x * 10) / 100;
    rounded_down = rounded_down *10;
    return rounded_down;
    } else {
    float rounded_down = ceilf(x * 10) / 100;
    rounded_down = rounded_down *10;
    return rounded_down;
    }
}

int getRand(){
	return rand() % 100;
}

bool isWall(float x, float y){
	float tempX = adjust(x);
	float tempY = adjust(y);
	int coordenadaX = convertePacX(tempX, tempY);
	int coordenadaY = convertePacY(tempX, tempY);
		
	if (path[coordenadaX][coordenadaY] == 4)
		return true;
	return false;
}		