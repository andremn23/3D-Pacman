#ifndef __FOOD_H__
#define __FOOD_H__

class Food {
	GLfloat _s;
	GLfloat _tX;
	GLfloat _tY;

public:
	Food(GLfloat s, GLfloat tX, GLfloat tY) 
		: _s(s),_tX(tX),_tY(tY){}
	void draw();
	float getPacX();
	float getPacY();
};

#endif
