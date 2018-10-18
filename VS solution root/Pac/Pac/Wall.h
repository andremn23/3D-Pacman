#ifndef __WALL_H__
#define __WALL_H__

class Wall {
	GLfloat _sX;
	GLfloat _sY;
	GLfloat _tX;
	GLfloat _tY;

public:
	Wall(GLfloat sX, GLfloat sY, GLfloat tX, GLfloat tY) 
		: _sX(sX), _sY(sY), _tX(tX), _tY(tY){}
	void draw();
};

#endif