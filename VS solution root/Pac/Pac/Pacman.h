#ifndef __PACMAN_H__
#define __PACMAN_H__

#include "Movable.h"
#include "Labyrinth.h"

class Pacman : public Movable{
	bool _divineIntervention;
	public:
		Pacman() : _divineIntervention(false) {
			_x = 0;
			_y = -9;
			_direction = "left";
		}
		~Pacman(){}
		void draw(void);
		void drawFace(void);
		void dI(){ _divineIntervention = true; }
};
#endif