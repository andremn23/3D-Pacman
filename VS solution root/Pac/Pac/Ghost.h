#ifndef __GHOST_H__
#define __GHOST_H__

#include "Movable.h"

class Ghost : public Movable{
	int _queue;
	float _r;
	float _g;
	float _b;
	double _eyeAngle;
	bool _scared;
	bool _caged;
	bool _free;
	bool _dead;

	public:
		Ghost(float r, float g, float b) :
			_r(r), _g(g), _b(b), _scared(false), _caged(true), _free(false), _dead(false) {
		}
		void setQueue(int queued){
			_queue = queued;
		}
		int getQueue(){ return _queue;}
		void draw(void);
		void drawFace(void);
		void eyeAngle(double pacX, double pacY);
		bool moveAway();
		void moveOnCage(double step);
		double getAngle(){ return _eyeAngle; }
		void nextTurn(double step);
		void scared() { _scared = true; }
		void normal() { _scared = false; }
		bool isScared() { return _scared; }
		bool isCaged() { return _caged; }
		bool isFree() { return _free; }
		void unlock() { _free = true; }
		void lock(){ _free = false;}
		void gotOut() { _caged = false; }
		void gotIn(){_caged = true;}
		void die(void) { _dead = true; _direction = "left"; _turn = "left"; _x = 0; _y = 0; _caged = true; _free = false;}
		void revive(void) { _dead = false; }
		bool isDead() { return _dead; }
};
#endif