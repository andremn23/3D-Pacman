
#include "Labyrinth.h"
#include "AuxFuncs.h"

//Variavel que guarda a pontuação
int score = 0;

bool ballUpLeft = true;
bool ballUpRight = true;
bool ballDownLeft = true;
bool ballDownRight = true;
//Funçao que converte a posição x da matriz na respectiva posição do pacman (pacX)
float converteX(float coordenadaY){
	float pacX = 0;
	pacX = -14.5 + coordenadaY;
	return pacX;
}

//Funçao que converte a posição y da matriz na respectiva posição do pacman (pacY)
float converteY(float coordenadaX) {
	float pacY = 0;
    pacY = 15 - coordenadaX;
    return pacY;
}

void Labyrinth::create() {
	
	int x, y;
	float varX, varY;
	
		//Paredes//
				Wall *w = new Wall(1,1,-14,14.5);
		addWall(w);
		w = new Wall(1,1,-13,14.5);
		addWall(w);
		w = new Wall(1,1,-12,14.5);
		addWall(w);
		w = new Wall(1,1,-11,14.5);
		addWall(w);
		w = new Wall(1,1,-10,14.5);
		addWall(w);
		w = new Wall(1,1,-9,14.5);
		addWall(w);
		w = new Wall(1,1,-8,14.5);
		addWall(w);
		w = new Wall(1,1,-7,14.5);
		addWall(w);
		w = new Wall(1,1,-6,14.5);
		addWall(w);
		w = new Wall(1,1,-5,14.5);
		addWall(w);
		w = new Wall(1,1,-4,14.5);
		addWall(w);
		w = new Wall(1,1,-3,14.5);
		addWall(w);
		w = new Wall(1,1,-2,14.5);
		addWall(w);
		w = new Wall(1,1,-1,14.5);
		addWall(w);
		w = new Wall(1,1,0,14.5);
		addWall(w);
		w = new Wall(1,1,1,14.5);
		addWall(w);
		w = new Wall(1,1,2,14.5);
		addWall(w);
		w = new Wall(1,1,3,14.5);
		addWall(w);
		w = new Wall(1,1,4,14.5);
		addWall(w);
		w = new Wall(1,1,5,14.5);
		addWall(w);
		w = new Wall(1,1,6,14.5);
		addWall(w);
		w = new Wall(1,1,7,14.5);
		addWall(w);
		w = new Wall(1,1,8,14.5);
		addWall(w);
		w = new Wall(1,1,9,14.5);
		addWall(w);
		w = new Wall(1,1,10,14.5);
		addWall(w);
		w = new Wall(1,1,11,14.5);
		addWall(w);
		w = new Wall(1,1,12,14.5);
		addWall(w);
		w = new Wall(1,1,13,14.5);
		addWall(w);
		w = new Wall(1,1,14,14.5);
		addWall(w);

		//w = new Wall(1,10,14,9.5);
		//addWall(w);
		w = new Wall(1,1,14,5.5);
		addWall(w);
		w = new Wall(1,1,14,6.5);
		addWall(w);
		w = new Wall(1,1,14,7.5);
		addWall(w);
		w = new Wall(1,1,14,8.5);
		addWall(w);
		w = new Wall(1,1,14,9.5);
		addWall(w);
		w = new Wall(1,1,14,10.5);
		addWall(w);
		w = new Wall(1,1,14,11.5);
		addWall(w);
		w = new Wall(1,1,14,12.5);
		addWall(w);
		w = new Wall(1,1,14,13.5);
		addWall(w);
		
		//w = new Wall(6,1,11.5,4.5);
		//addWall(w); 
		w = new Wall(1,1,9,4.5);
		addWall(w);
		w = new Wall(1,1,10,4.5);
		addWall(w);
		w = new Wall(1,1,11,4.5);
		addWall(w);
		w = new Wall(1,1,12,4.5);
		addWall(w);
		w = new Wall(1,1,13,4.5);
		addWall(w);
		w = new Wall(1,1,14,4.5);
		addWall(w);

		//w = new Wall(1,2,9,3);
		//addWall(w);
		w = new Wall(1,1,9,2.5);
		addWall(w);
		w = new Wall(1,1,9,3.5);
		addWall(w);

		//w = new Wall(6,1,11.5,1.5);
		//addWall(w);
		w = new Wall(1,1,9,1.5);
		addWall(w);
		w = new Wall(1,1,10,1.5);
		addWall(w);
		w = new Wall(1,1,11,1.5);
		addWall(w);
		w = new Wall(1,1,12,1.5);
		addWall(w);
		w = new Wall(1,1,13,1.5);
		addWall(w);
		w = new Wall(1,1,14,1.5);
		addWall(w);

		//w = new Wall(6,1,11.5,-1.5);
		//addWall(w);
		w = new Wall(1,1,9,-1.5);
		addWall(w);
		w = new Wall(1,1,10,-1.5);
		addWall(w);
		w = new Wall(1,1,11,-1.5);
		addWall(w);
		w = new Wall(1,1,12,-1.5);
		addWall(w);
		w = new Wall(1,1,13,-1.5);
		addWall(w);
		w = new Wall(1,1,14,-1.5);
		addWall(w);

		//w = new Wall(1,2,9,-3);
		//addWall(w);
		w = new Wall(1,1,9,-2.5);
		addWall(w);
		w = new Wall(1,1,9,-3.5);
		addWall(w);

		//w = new Wall(6,1,11.5,-4.5);
		//addWall(w);
		w = new Wall(1,1,9,-4.5);
		addWall(w);
		w = new Wall(1,1,10,-4.5);
		addWall(w);
		w = new Wall(1,1,11,-4.5);
		addWall(w);
		w = new Wall(1,1,12,-4.5);
		addWall(w);
		w = new Wall(1,1,13,-4.5);
		addWall(w);
		w = new Wall(1,1,14,-4.5);
		addWall(w);

		//w = new Wall(1,12,14,-10.5);
		//addWall(w);
		w = new Wall(1,1,14,-5.5);
		addWall(w);
		w = new Wall(1,1,14,-6.5);
		addWall(w);
		w = new Wall(1,1,14,-7.5);
		addWall(w);
		w = new Wall(1,1,14,-8.5);
		addWall(w);
		w = new Wall(1,1,14,-9.5);
		addWall(w);
		w = new Wall(1,1,14,-10.5);
		addWall(w);
		w = new Wall(1,1,14,-11.5);
		addWall(w);
		w = new Wall(1,1,14,-12.5);
		addWall(w);
		w = new Wall(1,1,14,-13.5);
		addWall(w);
		w = new Wall(1,1,14,-14.5);
		addWall(w);
		w = new Wall(1,1,14,-15.5);
		addWall(w);
		
		//w = new Wall(2,1,12.5,-10.5);
		//addWall(w);
		w = new Wall(1,1,12,-10.5);
		addWall(w);
		w = new Wall(1,1,13,-10.5);
		addWall(w);

		//w = new Wall(2,1,-12.5,-10.5);
		//addWall(w);
		w = new Wall(1,1,-12,-10.5);
		addWall(w);
		w = new Wall(1,1,-13,-10.5);
		addWall(w);

		//w = new Wall(1,10,-14,9.5);
		//addWall(w);
		w = new Wall(1,1,-14,5.5);
		addWall(w);
		w = new Wall(1,1,-14,6.5);
		addWall(w);
		w = new Wall(1,1,-14,7.5);
		addWall(w);
		w = new Wall(1,1,-14,8.5);
		addWall(w);
		w = new Wall(1,1,-14,9.5);
		addWall(w);
		w = new Wall(1,1,-14,10.5);
		addWall(w);
		w = new Wall(1,1,-14,11.5);
		addWall(w);
		w = new Wall(1,1,-14,12.5);
		addWall(w);
		w = new Wall(1,1,-14,13.5);
		addWall(w);

		//w = new Wall(1,12,-14,-10.5);
		//addWall(w); 
		w = new Wall(1,1,-14,-5.5);
		addWall(w);
		w = new Wall(1,1,-14,-6.5);
		addWall(w);
		w = new Wall(1,1,-14,-7.5);
		addWall(w);
		w = new Wall(1,1,-14,-8.5);
		addWall(w);
		w = new Wall(1,1,-14,-9.5);
		addWall(w);
		w = new Wall(1,1,-14,-10.5);
		addWall(w);
		w = new Wall(1,1,-14,-11.5);
		addWall(w);
		w = new Wall(1,1,-14,-12.5);
		addWall(w);
		w = new Wall(1,1,-14,-13.5);
		addWall(w);
		w = new Wall(1,1,-14,-14.5);
		addWall(w);
		w = new Wall(1,1,-14,-15.5);
		addWall(w);
		
		//w = new Wall(6,1,-11.5,4.5);
		//addWall(w);
		w = new Wall(1,1,-9,4.5);
		addWall(w);
		w = new Wall(1,1,-10,4.5);
		addWall(w);
		w = new Wall(1,1,-11,4.5);
		addWall(w);
		w = new Wall(1,1,-12,4.5);
		addWall(w);
		w = new Wall(1,1,-13,4.5);
		addWall(w);
		w = new Wall(1,1,-14,4.5);
		addWall(w);

		//w = new Wall(1,2,-9,3);
		//addWall(w);
		w = new Wall(1,1,-9,3.5);
		addWall(w);
		w = new Wall(1,1,-9,2.5);
		addWall(w);

		//w = new Wall(6,1,-11.5,1.5);
		//addWall(w);
		w = new Wall(1,1,-9,1.5);
		addWall(w);
		w = new Wall(1,1,-10,1.5);
		addWall(w);
		w = new Wall(1,1,-11,1.5);
		addWall(w);
		w = new Wall(1,1,-12,1.5);
		addWall(w);
		w = new Wall(1,1,-13,1.5);
		addWall(w);
		w = new Wall(1,1,-14,1.5);
		addWall(w);

		//w = new Wall(6,1,-11.5,-1.5);
		//addWall(w); 
		w = new Wall(1,1,-9,-1.5);
		addWall(w);
		w = new Wall(1,1,-10,-1.5);
		addWall(w);
		w = new Wall(1,1,-11,-1.5);
		addWall(w);
		w = new Wall(1,1,-12,-1.5);
		addWall(w);
		w = new Wall(1,1,-13,-1.5);
		addWall(w);
		w = new Wall(1,1,-14,-1.5);
		addWall(w);

		//w = new Wall(1,2,-9,-3);
		//addWall(w);
		w = new Wall(1,1,-9,-3.5);
		addWall(w);
		w = new Wall(1,1,-9,-2.5);
		addWall(w);

		//w = new Wall(3,1,-10,7.5);
		//addWall(w);
		w = new Wall(1,1,-9,7.5);
		addWall(w);
		w = new Wall(1,1,-10,7.5);
		addWall(w);
		w = new Wall(1,1,-11,7.5);
		addWall(w);

		//w = new Wall(3,1,10,7.5);
		//addWall(w);
		w = new Wall(1,1,9,7.5);
		addWall(w);
		w = new Wall(1,1,10,7.5);
		addWall(w);
		w = new Wall(1,1,11,7.5);
		addWall(w);

		//w = new Wall(6,1,-11.5,-4.5);
		//addWall(w);
		w = new Wall(1,1,-9,-4.5);
		addWall(w);
		w = new Wall(1,1,-10,-4.5);
		addWall(w);
		w = new Wall(1,1,-11,-4.5);
		addWall(w);
		w = new Wall(1,1,-12,-4.5);
		addWall(w);
		w = new Wall(1,1,-13,-4.5);
		addWall(w);
		w = new Wall(1,1,-14,-4.5);
		addWall(w);
		
		//w = new Wall(29,1,0,-16.5);
		//addWall(w); 
		w = new Wall(1,1,-14,-16.5);
		addWall(w);
		w = new Wall(1,1,-13,-16.5);
		addWall(w);
		w = new Wall(1,1,-12,-16.5);
		addWall(w);
		w = new Wall(1,1,-11,-16.5);
		addWall(w);
		w = new Wall(1,1,-10,-16.5);
		addWall(w);
		w = new Wall(1,1,-9,-16.5);
		addWall(w);
		w = new Wall(1,1,-8,-16.5);
		addWall(w);
		w = new Wall(1,1,-7,-16.5);
		addWall(w);
		w = new Wall(1,1,-6,-16.5);
		addWall(w);
		w = new Wall(1,1,-5,-16.5);
		addWall(w);
		w = new Wall(1,1,-4,-16.5);
		addWall(w);
		w = new Wall(1,1,-3,-16.5);
		addWall(w);
		w = new Wall(1,1,-2,-16.5);
		addWall(w);
		w = new Wall(1,1,-1,-16.5);
		addWall(w);
		w = new Wall(1,1,0,-16.5);
		addWall(w);
		w = new Wall(1,1,1,-16.5);
		addWall(w);
		w = new Wall(1,1,2,-16.5);
		addWall(w);
		w = new Wall(1,1,3,-16.5);
		addWall(w);
		w = new Wall(1,1,4,-16.5);
		addWall(w);
		w = new Wall(1,1,5,-16.5);
		addWall(w);
		w = new Wall(1,1,6,-16.5);
		addWall(w);
		w = new Wall(1,1,7,-16.5);
		addWall(w);
		w = new Wall(1,1,8,-16.5);
		addWall(w);
		w = new Wall(1,1,9,-16.5);
		addWall(w);
		w = new Wall(1,1,10,-16.5);
		addWall(w);
		w = new Wall(1,1,11,-16.5);
		addWall(w);
		w = new Wall(1,1,12,-16.5);
		addWall(w);
		w = new Wall(1,1,13,-16.5);
		addWall(w);
		w = new Wall(1,1,14,-16.5);
		addWall(w);

		//w = new Wall(3,2,10,11);
		//addWall(w); 
		w = new Wall(1,1,9,10.5);
		addWall(w);
		w = new Wall(1,1,10,10.5);
		addWall(w);
		w = new Wall(1,1,11,10.5);
		addWall(w);
		w = new Wall(1,1,9,11.5);
		addWall(w);
		w = new Wall(1,1,10,11.5);
		addWall(w);
		w = new Wall(1,1,11,11.5);
		addWall(w);

		//w = new Wall(4,2,4.5f,11);
		//addWall(w);
		w = new Wall(1,1,3,10.5);
		addWall(w);
		w = new Wall(1,1,4,10.5);
		addWall(w);
		w = new Wall(1,1,5,10.5);
		addWall(w);
		w = new Wall(1,1,6,10.5);
		addWall(w);
		w = new Wall(1,1,3,11.5);
		addWall(w);
		w = new Wall(1,1,4,11.5);
		addWall(w);
		w = new Wall(1,1,5,11.5);
		addWall(w);
		w = new Wall(1,1,6,11.5);
		addWall(w);

		//w = new Wall(1,4,0,12);
		//addWall(w);
		w = new Wall(1,1,0,10.5);
		addWall(w);
		w = new Wall(1,1,0,11.5);
		addWall(w);
		w = new Wall(1,1,0,12.5);
		addWall(w);
		w = new Wall(1,1,0,13.5);
		addWall(w);

		//w = new Wall(3,2,-10,11);
		//addWall(w); 
		w = new Wall(1,1,-9,10.5);
		addWall(w);
		w = new Wall(1,1,-10,10.5);
		addWall(w);
		w = new Wall(1,1,-11,10.5);
		addWall(w);
		w = new Wall(1,1,-9,11.5);
		addWall(w);
		w = new Wall(1,1,-10,11.5);
		addWall(w);
		w = new Wall(1,1,-11,11.5);
		addWall(w);

		//w = new Wall(4,2,-4.5f,11);
		//addWall(w); 
		w = new Wall(1,1,-3,10.5);
		addWall(w);
		w = new Wall(1,1,-4,10.5);
		addWall(w);
		w = new Wall(1,1,-5,10.5);
		addWall(w);
		w = new Wall(1,1,-6,10.5);
		addWall(w);
		w = new Wall(1,1,-3,11.5);
		addWall(w);
		w = new Wall(1,1,-4,11.5);
		addWall(w);
		w = new Wall(1,1,-5,11.5);
		addWall(w);
		w = new Wall(1,1,-6,11.5);
		addWall(w);


		//w = new Wall(1,4,-6,-3);
		//addWall(w); 
		w = new Wall(1,1,-6,-1.5);
		addWall(w);
		w = new Wall(1,1,-6,-2.5);
		addWall(w);
		w = new Wall(1,1,-6,-3.5);
		addWall(w);
		w = new Wall(1,1,-6,-4.5);
		addWall(w);

		//w = new Wall(1,4,6,-3);
		//addWall(w); 
		w = new Wall(1,1,6,-1.5);
		addWall(w);
		w = new Wall(1,1,6,-2.5);
		addWall(w);
		w = new Wall(1,1,6,-3.5);
		addWall(w);
		w = new Wall(1,1,6,-4.5);
		addWall(w);

		//w = new Wall(4,1,-4.5,-7.5);
		//addWall(w); 
		w = new Wall(1,1,-3,-7.5);
		addWall(w);
		w = new Wall(1,1,-4,-7.5);
		addWall(w);
		w = new Wall(1,1,-5,-7.5);
		addWall(w);
		w = new Wall(1,1,-6,-7.5);
		addWall(w);

		//w = new Wall(4,1,4.5,-7.5);
		//addWall(w); 
		w = new Wall(1,1,3,-7.5);
		addWall(w);
		w = new Wall(1,1,4,-7.5);
		addWall(w);
		w = new Wall(1,1,5,-7.5);
		addWall(w);
		w = new Wall(1,1,6,-7.5);
		addWall(w);

		//w = new Wall(1,7,6,4.5);
		//addWall(w); 
		w = new Wall(1,1,6,1.5);
		addWall(w);
		w = new Wall(1,1,6,2.5);
		addWall(w);
		w = new Wall(1,1,6,3.5);
		addWall(w);
		w = new Wall(1,1,6,4.5);
		addWall(w);
		w = new Wall(1,1,6,5.5);
		addWall(w);
		w = new Wall(1,1,6,6.5);
		addWall(w);
		w = new Wall(1,1,6,7.5);
		addWall(w);

		//w = new Wall(1,7,-6,4.5);
		//addWall(w); 
		w = new Wall(1,1,-6,1.5);
		addWall(w);
		w = new Wall(1,1,-6,2.5);
		addWall(w);
		w = new Wall(1,1,-6,3.5);
		addWall(w);
		w = new Wall(1,1,-6,4.5);
		addWall(w);
		w = new Wall(1,1,-6,5.5);
		addWall(w);
		w = new Wall(1,1,-6,6.5);
		addWall(w);
		w = new Wall(1,1,-6,7.5);
		addWall(w);

		//w = new Wall(1,3,-6,-11.5);
		//addWall(w); 
		w = new Wall(1,1,-6,-10.5);
		addWall(w);
		w = new Wall(1,1,-6,-11.5);
		addWall(w);
		w = new Wall(1,1,-6,-12.5);
		addWall(w);

		//w = new Wall(1,3,6,-11.5);
		//addWall(w); 
		w = new Wall(1,1,6,-10.5);
		addWall(w);
		w = new Wall(1,1,6,-11.5);
		addWall(w);
		w = new Wall(1,1,6,-12.5);
		addWall(w);


		//w = new Wall(7,1,0,7.5);
		//addWall(w); 
		w = new Wall(1,1,-3,7.5);
		addWall(w);
		w = new Wall(1,1,-2,7.5);
		addWall(w);
		w = new Wall(1,1,-1,7.5);
		addWall(w);
		w = new Wall(1,1,0,7.5);
		addWall(w);
		w = new Wall(1,1,1,7.5);
		addWall(w);
		w = new Wall(1,1,2,7.5);
		addWall(w);
		w = new Wall(1,1,3,7.5);
		addWall(w);

		//w = new Wall(1,4,0,6);
		//addWall(w); 
		w = new Wall(1,1,0,4.5);
		addWall(w);
		w = new Wall(1,1,0,5.5);
		addWall(w);
		w = new Wall(1,1,0,6.5);
		addWall(w);

		//w = new Wall(4,1,4.5,4.5);
		//addWall(w); 
		w = new Wall(1,1,3,4.5);
		addWall(w);
		w = new Wall(1,1,4,4.5);
		addWall(w);
		w = new Wall(1,1,5,4.5);
		addWall(w);

		//w = new Wall(4,1,-4.5,4.5);
		//addWall(w); 
		w = new Wall(1,1,-3,4.5);
		addWall(w);
		w = new Wall(1,1,-4,4.5);
		addWall(w);
		w = new Wall(1,1,-5,4.5);
		addWall(w);
		

		//w = new Wall(7,1,0,-4.5);
		//addWall(w); 
		w = new Wall(1,1,-3,-4.5);
		addWall(w);
		w = new Wall(1,1,-2,-4.5);
		addWall(w);
		w = new Wall(1,1,-1,-4.5);
		addWall(w);
		w = new Wall(1,1,0,-4.5);
		addWall(w);
		w = new Wall(1,1,1,-4.5);
		addWall(w);
		w = new Wall(1,1,2,-4.5);
		addWall(w);
		w = new Wall(1,1,3,-4.5);
		addWall(w);

		//w = new Wall(1,4,0,-6);
		//addWall(w); 
		w = new Wall(1,1,0,-5.5);
		addWall(w);
		w = new Wall(1,1,0,-6.5);
		addWall(w);
		w = new Wall(1,1,0,-7.5);
		addWall(w);
	
		//w = new Wall(7,1,0,-10.5);
		//addWall(w); 
		w = new Wall(1,1,-3,-10.5);
		addWall(w);
		w = new Wall(1,1,-2,-10.5);
		addWall(w);
		w = new Wall(1,1,-1,-10.5);
		addWall(w);
		w = new Wall(1,1,0,-10.5);
		addWall(w);
		w = new Wall(1,1,1,-10.5);
		addWall(w);
		w = new Wall(1,1,2,-10.5);
		addWall(w);
		w = new Wall(1,1,3,-10.5);
		addWall(w);

		//w = new Wall(1,4,0,-12);
		//addWall(w); 
		w = new Wall(1,1,0,-11.5);
		addWall(w);
		w = new Wall(1,1,0,-12.5);
		addWall(w);
		w = new Wall(1,1,0,-13.5);
		addWall(w);

		//w = new Wall(9,1,-7,-13.5);
		//addWall(w); 
		w = new Wall(1,1,-3,-13.5);
		addWall(w);
		w = new Wall(1,1,-4,-13.5);
		addWall(w);
		w = new Wall(1,1,-5,-13.5);
		addWall(w);
		w = new Wall(1,1,-6,-13.5);
		addWall(w);
		w = new Wall(1,1,-7,-13.5);
		addWall(w);
		w = new Wall(1,1,-8,-13.5);
		addWall(w);
		w = new Wall(1,1,-9,-13.5);
		addWall(w);
		w = new Wall(1,1,-10,-13.5);
		addWall(w);
		w = new Wall(1,1,-11,-13.5);
		addWall(w);

		//w = new Wall(9,1,7,-13.5);
		//addWall(w); 
		w = new Wall(1,1,3,-13.5);
		addWall(w);
		w = new Wall(1,1,4,-13.5);
		addWall(w);
		w = new Wall(1,1,5,-13.5);
		addWall(w);
		w = new Wall(1,1,6,-13.5);
		addWall(w);
		w = new Wall(1,1,7,-13.5);
		addWall(w);
		w = new Wall(1,1,8,-13.5);
		addWall(w);
		w = new Wall(1,1,9,-13.5);
		addWall(w);
		w = new Wall(1,1,10,-13.5);
		addWall(w);
		w = new Wall(1,1,11,-13.5);
		addWall(w);

		//w = new Wall(3,1,10,-7.5);
		//addWall(w); 
		w = new Wall(1,1,10,-7.5);
		addWall(w);
		w = new Wall(1,1,11,-7.5);
		addWall(w);

		//w = new Wall(3,1,-10,-7.5);
		//addWall(w); 
		w = new Wall(1,1,-10,-7.5);
		addWall(w);
		w = new Wall(1,1,-11,-7.5);
		addWall(w);
		
		//w = new Wall(1,4,-9,-9);
		//addWall(w); 
		w = new Wall(1,1,-9,-7.5);
		addWall(w);
		w = new Wall(1,1,-9,-8.5);
		addWall(w);
		w = new Wall(1,1,-9,-9.5);
		addWall(w);
		w = new Wall(1,1,-9,-10.5);
		addWall(w);

		//w = new Wall(1,4,9,-9);
		//addWall(w); 
		w = new Wall(1,1,9,-7.5);
		addWall(w);
		w = new Wall(1,1,9,-8.5);
		addWall(w);
		w = new Wall(1,1,9,-9.5);
		addWall(w);
		w = new Wall(1,1,9,-10.5);
		addWall(w);

		//w = new Wall(7,1,0,1.5);
		//addWall(w); 
		w = new Wall(1,1,-2,1.5);
		addWall(w);
		w = new Wall(1.5,1,-1.6,1.5);
		addWall(w);
		w = new Wall(1.5,1,1.6,1.5);
		addWall(w);
		w = new Wall(1,1,2,1.5);
		addWall(w);
		//w = new Wall(7,1,0,-1.5);
		//addWall(w); 

		w = new Wall(1,1,-3,-1.5);
		addWall(w);
		w = new Wall(1,1,-2,-1.5);
		addWall(w);
		w = new Wall(1,1,-1,-1.5);
		addWall(w);
		w = new Wall(1,1,0,-1.5);
		addWall(w);
		w = new Wall(1,1,1,-1.5);
		addWall(w);
		w = new Wall(1,1,2,-1.5);
		addWall(w);
		w = new Wall(1,1,3,-1.5);
		addWall(w);

		
		/*w = new Wall(1,3,3,0);
		addWall(w); */
		w = new Wall(1,1,3,-0.5);
		addWall(w);
		w = new Wall(1,1,3,0.5);
		addWall(w);
		w = new Wall(1,1,3,1.5);
		addWall(w);
		/*w = new Wall(1,3,-3,0);
		addWall(w); */
		w = new Wall(1,1,-3,-0.5);
		addWall(w);
		w = new Wall(1,1,-3,0.5);
		addWall(w);
		w = new Wall(1,1,-3,1.5);
		addWall(w);


		//

		//Chão//
		Floor *fl = new Floor(-14.5,-15,-12.5,-17);
		addFloor(fl);

		fl = new Floor(-12.5,-15,-10.5,-17);
		addFloor(fl);
		fl = new Floor(-10.5,-15,-8.5,-17);
		addFloor(fl);
		fl = new Floor(-8.5,-15,-6.5,-17);
		addFloor(fl);
		fl = new Floor(-6.5,-15,-4.5,-17);
		addFloor(fl);
		fl = new Floor(-4.5,-15,-2.5,-17);
		addFloor(fl);
		fl = new Floor(-2.5,-15,-0.5,-17);
		addFloor(fl);
		fl = new Floor(-0.5,-15,1.5,-17);
		addFloor(fl);
		fl = new Floor(1.5,-15,3.5,-17);
		addFloor(fl);
		fl = new Floor(3.5,-15,5.5,-17);
		addFloor(fl);
		fl = new Floor(5.5,-15,7.5,-17);
		addFloor(fl);
		fl = new Floor(7.5,-15,9.5,-17);
		addFloor(fl);
		fl = new Floor(9.5,-15,11.5,-17);
		addFloor(fl);
		fl = new Floor(11.5,-15,13.5,-17);
		addFloor(fl);

		fl = new Floor(-14.5,-13,-12.5,-15);
		addFloor(fl);
		fl = new Floor(-12.5,-13,-10.5,-15);
		addFloor(fl);
		fl = new Floor(-10.5,-13,-8.5,-15);
		addFloor(fl);
		fl = new Floor(-8.5,-13,-6.5,-15);
		addFloor(fl);
		fl = new Floor(-6.5,-13,-4.5,-15);
		addFloor(fl);
		fl = new Floor(-4.5,-13,-2.5,-15);
		addFloor(fl);
		fl = new Floor(-2.5,-13,-0.5,-15);
		addFloor(fl);
		fl = new Floor(-0.5,-13,1.5,-15);
		addFloor(fl);
		fl = new Floor(1.5,-13,3.5,-15);
		addFloor(fl);
		fl = new Floor(3.5,-13,5.5,-15);
		addFloor(fl);
		fl = new Floor(5.5,-13,7.5,-15);
		addFloor(fl);
		fl = new Floor(7.5,-13,9.5,-15);
		addFloor(fl);
		fl = new Floor(9.5,-13,11.5,-15);
		addFloor(fl);
		fl = new Floor(11.5,-13,13.5,-15);
		addFloor(fl);

		fl = new Floor(-14.5,-11,-12.5,-13);
		addFloor(fl);
		fl = new Floor(-12.5,-11,-10.5,-13);
		addFloor(fl);
		fl = new Floor(-10.5,-11,-8.5,-13);
		addFloor(fl);
		fl = new Floor(-8.5,-11,-6.5,-13);
		addFloor(fl);
		fl = new Floor(-6.5,-11,-4.5,-13);
		addFloor(fl);
		fl = new Floor(-4.5,-11,-2.5,-13);
		addFloor(fl);
		fl = new Floor(-2.5,-11,-0.5,-13);
		addFloor(fl);
		fl = new Floor(-0.5,-11,1.5,-13);
		addFloor(fl);
		fl = new Floor(1.5,-11,3.5,-13);
		addFloor(fl);
		fl = new Floor(3.5,-11,5.5,-13);
		addFloor(fl);
		fl = new Floor(5.5,-11,7.5,-13);
		addFloor(fl);
		fl = new Floor(7.5,-11,9.5,-13);
		addFloor(fl);
		fl = new Floor(9.5,-11,11.5,-13);
		addFloor(fl);
		fl = new Floor(11.5,-11,13.5,-13);
		addFloor(fl);
		
		fl = new Floor(-14.5,-9,-12.5,-11);
		addFloor(fl);
		fl = new Floor(-12.5,-9,-10.5,-11);
		addFloor(fl);
		fl = new Floor(-10.5,-9,-8.5,-11);
		addFloor(fl);
		fl = new Floor(-8.5,-9,-6.5,-11);
		addFloor(fl);
		fl = new Floor(-6.5,-9,-4.5,-11);
		addFloor(fl);
		fl = new Floor(-4.5,-9,-2.5,-11);
		addFloor(fl);
		fl = new Floor(-2.5,-9,-0.5,-11);
		addFloor(fl);
		fl = new Floor(-0.5,-9,1.5,-11);
		addFloor(fl);
		fl = new Floor(1.5,-9,3.5,-11);
		addFloor(fl);
		fl = new Floor(3.5,-9,5.5,-11);
		addFloor(fl);
		fl = new Floor(5.5,-9,7.5,-11);
		addFloor(fl);
		fl = new Floor(7.5,-9,9.5,-11);
		addFloor(fl);
		fl = new Floor(9.5,-9,11.5,-11);
		addFloor(fl);
		fl = new Floor(11.5,-9,13.5,-11);
		addFloor(fl);

		fl = new Floor(-14.5,-7,-12.5,-9);
		addFloor(fl);
		fl = new Floor(-12.5,-7,-10.5,-9);
		addFloor(fl);
		fl = new Floor(-10.5,-7,-8.5,-9);
		addFloor(fl);
		fl = new Floor(-8.5,-7,-6.5,-9);
		addFloor(fl);
		fl = new Floor(-6.5,-7,-4.5,-9);
		addFloor(fl);
		fl = new Floor(-4.5,-7,-2.5,-9);
		addFloor(fl);
		fl = new Floor(-2.5,-7,-0.5,-9);
		addFloor(fl);
		fl = new Floor(-0.5,-7,1.5,-9);
		addFloor(fl);
		fl = new Floor(1.5,-7,3.5,-9);
		addFloor(fl);
		fl = new Floor(3.5,-7,5.5,-9);
		addFloor(fl);
		fl = new Floor(5.5,-7,7.5,-9);
		addFloor(fl);
		fl = new Floor(7.5,-7,9.5,-9);
		addFloor(fl);
		fl = new Floor(9.5,-7,11.5,-9);
		addFloor(fl);
		fl = new Floor(11.5,-7,13.5,-9);
		addFloor(fl);

		fl = new Floor(-14.5,-5,-12.5,-7);
		addFloor(fl);
		fl = new Floor(-12.5,-5,-10.5,-7);
		addFloor(fl);
		fl = new Floor(-10.5,-5,-8.5,-7);
		addFloor(fl);
		fl = new Floor(-8.5,-5,-6.5,-7);
		addFloor(fl);
		fl = new Floor(-6.5,-5,-4.5,-7);
		addFloor(fl);
		fl = new Floor(-4.5,-5,-2.5,-7);
		addFloor(fl);
		fl = new Floor(-2.5,-5,-0.5,-7);
		addFloor(fl);
		fl = new Floor(-0.5,-5,1.5,-7);
		addFloor(fl);
		fl = new Floor(1.5,-5,3.5,-7);
		addFloor(fl);
		fl = new Floor(3.5,-5,5.5,-7);
		addFloor(fl);
		fl = new Floor(5.5,-5,7.5,-7);
		addFloor(fl);
		fl = new Floor(7.5,-5,9.5,-7);
		addFloor(fl);
		fl = new Floor(9.5,-5,11.5,-7);
		addFloor(fl);
		fl = new Floor(11.5,-5,13.5,-7);
		addFloor(fl);

		
		fl = new Floor(-8.5,-3,-6.5,-5);
		addFloor(fl);
		fl = new Floor(-6.5,-3,-4.5,-5);
		addFloor(fl);
		fl = new Floor(-4.5,-3,-2.5,-5);
		addFloor(fl);
		fl = new Floor(-2.5,-3,-0.5,-5);
		addFloor(fl);
		fl = new Floor(-0.5,-3,1.5,-5);
		addFloor(fl);
		fl = new Floor(1.5,-3,3.5,-5);
		addFloor(fl);
		fl = new Floor(3.5,-3,5.5,-5);
		addFloor(fl);
		fl = new Floor(5.5,-3,7.5,-5);
		addFloor(fl);
		fl = new Floor(7.5,-3,9.5,-5);
		addFloor(fl);

		fl = new Floor(-8.5,-1,-6.5,-3);
		addFloor(fl);
		fl = new Floor(-6.5,-1,-4.5,-3);
		addFloor(fl);
		fl = new Floor(-4.5,-1,-2.5,-3);
		addFloor(fl);
		fl = new Floor(-2.5,-1,-0.5,-3);
		addFloor(fl);
		fl = new Floor(-0.5,-1,1.5,-3);
		addFloor(fl);
		fl = new Floor(1.5,-1,3.5,-3);
		addFloor(fl);
		fl = new Floor(3.5,-1,5.5,-3);
		addFloor(fl);
		fl = new Floor(5.5,-1,7.5,-3);
		addFloor(fl);
		fl = new Floor(7.5,-1,9.5,-3);
		addFloor(fl);

		fl = new Floor(-14.5,1,-12.5,-1);
		addFloor(fl);
		fl = new Floor(-12.5,1,-10.5,-1);
		addFloor(fl);
		fl = new Floor(-10.5,1,-8.5,-1);
		addFloor(fl);
		fl = new Floor(-8.5,1,-6.5,-1);
		addFloor(fl);
		fl = new Floor(-6.5,1,-4.5,-1);
		addFloor(fl);
		fl = new Floor(-4.5,1,-2.5,-1);
		addFloor(fl);
		fl = new Floor(-2.5,1,-0.5,-1);
		addFloor(fl);
		fl = new Floor(-0.5,1,1.5,-1);
		addFloor(fl);
		fl = new Floor(1.5,1,3.5,-1);
		addFloor(fl);
		fl = new Floor(3.5,1,5.5,-1);
		addFloor(fl);
		fl = new Floor(5.5,1,7.5,-1);
		addFloor(fl);
		fl = new Floor(7.5,1,9.5,-1);
		addFloor(fl);
		fl = new Floor(9.5,1,11.5,-1);
		addFloor(fl);
		fl = new Floor(11.5,1,13.5,-1);
		addFloor(fl);
		fl = new Floor(13.5,1,14.5,-1);
		addFloor(fl);

		fl = new Floor(-8.5,3,-6.5,1);
		addFloor(fl);
		fl = new Floor(-6.5,3,-4.5,1);
		addFloor(fl);
		fl = new Floor(-4.5,3,-2.5,1);
		addFloor(fl);
		fl = new Floor(-2.5,3,-0.5,1);
		addFloor(fl);
		fl = new Floor(-0.5,3,1.5,1);
		addFloor(fl);
		fl = new Floor(1.5,3,3.5,1);
		addFloor(fl);
		fl = new Floor(3.5,3,5.5,1);
		addFloor(fl);
		fl = new Floor(5.5,3,7.5,1);
		addFloor(fl);
		fl = new Floor(7.5,3,9.5,1);
		addFloor(fl);

		fl = new Floor(-8.5,5,-6.5,3);
		addFloor(fl);
		fl = new Floor(-6.5,5,-4.5,3);
		addFloor(fl);
		fl = new Floor(-4.5,5,-2.5,3);
		addFloor(fl);
		fl = new Floor(-2.5,5,-0.5,3);
		addFloor(fl);
		fl = new Floor(-0.5,5,1.5,3);
		addFloor(fl);
		fl = new Floor(1.5,5,3.5,3);
		addFloor(fl);
		fl = new Floor(3.5,5,5.5,3);
		addFloor(fl);
		fl = new Floor(5.5,5,7.5,3);
		addFloor(fl);
		fl = new Floor(7.5,5,9.5,3);
		addFloor(fl);

		fl = new Floor(-14.5,7,-12.5,5);
		addFloor(fl);
		fl = new Floor(-12.5,7,-10.5,5);
		addFloor(fl);
		fl = new Floor(-10.5,7,-8.5,5);
		addFloor(fl);
		fl = new Floor(-8.5,7,-6.5,5);
		addFloor(fl);
		fl = new Floor(-6.5,7,-4.5,5);
		addFloor(fl);
		fl = new Floor(-4.5,7,-2.5,5);
		addFloor(fl);
		fl = new Floor(-2.5,7,-0.5,5);
		addFloor(fl);
		fl = new Floor(-0.5,7,1.5,5);
		addFloor(fl);
		fl = new Floor(1.5,7,3.5,5);
		addFloor(fl);
		fl = new Floor(3.5,7,5.5,5);
		addFloor(fl);
		fl = new Floor(5.5,7,7.5,5);
		addFloor(fl);
		fl = new Floor(7.5,7,9.5,5);
		addFloor(fl);
		fl = new Floor(9.5,7,11.5,5);
		addFloor(fl);
		fl = new Floor(11.5,7,13.5,5);
		addFloor(fl);
		fl = new Floor(12.5,7,14.5,5);
		addFloor(fl);
		

		fl = new Floor(-14.5,9,-12.5,7);
		addFloor(fl);
		fl = new Floor(-12.5,9,-10.5,7);
		addFloor(fl);
		fl = new Floor(-10.5,9,-8.5,7);
		addFloor(fl);
		fl = new Floor(-8.5,9,-6.5,7);
		addFloor(fl);
		fl = new Floor(-6.5,9,-4.5,7);
		addFloor(fl);
		fl = new Floor(-4.5,9,-2.5,7);
		addFloor(fl);
		fl = new Floor(-2.5,9,-0.5,7);
		addFloor(fl);
		fl = new Floor(-0.5,9,1.5,7);
		addFloor(fl);
		fl = new Floor(1.5,9,3.5,7);
		addFloor(fl);
		fl = new Floor(3.5,9,5.5,7);
		addFloor(fl);
		fl = new Floor(5.5,9,7.5,7);
		addFloor(fl);
		fl = new Floor(7.5,9,9.5,7);
		addFloor(fl);
		fl = new Floor(9.5,9,11.5,7);
		addFloor(fl);
		fl = new Floor(11.5,9,13.5,7);
		addFloor(fl);
		fl = new Floor(12.5,9,14.5,7);
		addFloor(fl);

		fl = new Floor(-14.5,11,-12.5,9);
		addFloor(fl);
		fl = new Floor(-12.5,11,-10.5,9);
		addFloor(fl);
		fl = new Floor(-10.5,11,-8.5,9);
		addFloor(fl);
		fl = new Floor(-8.5,11,-6.5,9);
		addFloor(fl);
		fl = new Floor(-6.5,11,-4.5,9);
		addFloor(fl);
		fl = new Floor(-4.5,11,-2.5,9);
		addFloor(fl);
		fl = new Floor(-2.5,11,-0.5,9);
		addFloor(fl);
		fl = new Floor(-0.5,11,1.5,9);
		addFloor(fl);
		fl = new Floor(1.5,11,3.5,9);
		addFloor(fl);
		fl = new Floor(3.5,11,5.5,9);
		addFloor(fl);
		fl = new Floor(5.5,11,7.5,9);
		addFloor(fl);
		fl = new Floor(7.5,11,9.5,9);
		addFloor(fl);
		fl = new Floor(9.5,11,11.5,9);
		addFloor(fl);
		fl = new Floor(11.5,11,13.5,9);
		addFloor(fl);
		
		fl = new Floor(-14.5,13,-12.5,11);
		addFloor(fl);
		fl = new Floor(-12.5,13,-10.5,11);
		addFloor(fl);
		fl = new Floor(-10.5,13,-8.5,11);
		addFloor(fl);
		fl = new Floor(-8.5,13,-6.5,11);
		addFloor(fl);
		fl = new Floor(-6.5,13,-4.5,11);
		addFloor(fl);
		fl = new Floor(-4.5,13,-2.5,11);
		addFloor(fl);
		fl = new Floor(-2.5,13,-0.5,11);
		addFloor(fl);
		fl = new Floor(-0.5,13,1.5,11);
		addFloor(fl);
		fl = new Floor(1.5,13,3.5,11);
		addFloor(fl);
		fl = new Floor(3.5,13,5.5,11);
		addFloor(fl);
		fl = new Floor(5.5,13,7.5,11);
		addFloor(fl);
		fl = new Floor(7.5,13,9.5,11);
		addFloor(fl);
		fl = new Floor(9.5,13,11.5,11);
		addFloor(fl);
		fl = new Floor(11.5,13,13.5,11);
		addFloor(fl);
		
		fl = new Floor(-14.5,15,-12.5,13);
		addFloor(fl);
		fl = new Floor(-12.5,15,-10.5,13);
		addFloor(fl);
		fl = new Floor(-10.5,15,-8.5,13);
		addFloor(fl);
		fl = new Floor(-8.5,15,-6.5,13);
		addFloor(fl);
		fl = new Floor(-6.5,15,-4.5,13);
		addFloor(fl);
		fl = new Floor(-4.5,15,-2.5,13);
		addFloor(fl);
		fl = new Floor(-2.5,15,-0.5,13);
		addFloor(fl);
		fl = new Floor(-0.5,15,1.5,13);
		addFloor(fl);
		fl = new Floor(1.5,15,3.5,13);
		addFloor(fl);
		fl = new Floor(3.5,15,5.5,13);
		addFloor(fl);
		fl = new Floor(5.5,15,7.5,13);
		addFloor(fl);
		fl = new Floor(7.5,15,9.5,13);
		addFloor(fl);
		fl = new Floor(9.5,15,11.5,13);
		addFloor(fl);
		fl = new Floor(11.5,15,13.5,13);
		addFloor(fl);

	Food *fo = new Food(1,1,1); 
	

	for (y = 0; y< 30; y++){
			for (x = 0; x< 33; x++){

				if (pathFood[x][y] == 1){

					varX = converteX(y);
					varY = converteY(x);
					fo = new Food(0.2,varX,varY);
					addFood(fo);
					//bolas[x][y] = *fo;
				} else if (pathFood[x][y] == 2){
					varX = converteX(y);
					varY = converteY(x);
					fo = new Food(0.4,varX,varY);
					addFood(fo);
				}
			}
		}
			
}	



void Labyrinth::addWall(Wall *w) {
	_wall.push_back(w);
}

void Labyrinth::addFloor(Floor *f) {
	_floor.push_back(f);
}

void Labyrinth::addFood(Food *f) {
	_food.push_back(f);
}

Food Labyrinth::getFood(float pacX, float pacY){
	int i;	

	for (i = 0; i< _food.size(); i++)
		if (_food.at(i)->getPacX() == pacX && _food.at(i)->getPacY() == pacY)
			return *_food.at(i);
	}

void Labyrinth::deleteBall(float pacX, float pacY){
	int i;
	for (i = 0; i< _food.size(); i++)
		if (((_food.at(i)->getPacX() >= (pacX - 0.75)) && (_food.at(i)->getPacX() <= (pacX + 0.75)))
				&& ((_food.at(i)->getPacY() >= (pacY - 0.75)) && (_food.at(i)->getPacY() <= (pacY + 0.75)))){
			_food.erase(_food.begin()+i);
			score += 10;
	}
}

bool Labyrinth::existBall(float pacX, float pacY){
	if(pacX > 0 && pacY < 0)
		return ballDownRight;
	if(pacX > 0 && pacY > 0)
		return ballUpRight;
	if(pacX < 0 && pacY < 0)
		return ballDownLeft;
	if(pacX < 0 && pacY > 0)
		return ballUpLeft;
	return false;
}

void Labyrinth::eatBigBall(float pacX, float pacY){
	if(pacX > 0 && pacY < 0)
		ballDownRight = false;
	if(pacX > 0 && pacY > 0)
		ballUpRight = false;
	if(pacX < 0 && pacY < 0)
		ballDownLeft = false;
	if(pacX < 0 && pacY > 0)
		ballUpLeft = false;
}
int Labyrinth::getScore(){
	return score;
}


void Labyrinth::draw(){
	for(size_t sx = 0; sx < _wall.size(); sx++)
		_wall[sx]->draw();
	for(size_t sx = 0; sx < _floor.size(); sx++)
		_floor[sx]->draw();
	for(size_t sx = 0; sx < _food.size(); sx++)
		_food[sx]->draw();
}