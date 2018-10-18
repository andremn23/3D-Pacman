#ifndef __FLOOR_H__
#define __FLOOR_H__

class Floor {
	GLfloat _x1;
	GLfloat _y1; 
	GLfloat _x2; 
	GLfloat _y2;

public:
	Floor(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) 
		: _x1(x1),_y1(y1),_x2(x2),_y2(y2) {}
	void draw();
};

#endif