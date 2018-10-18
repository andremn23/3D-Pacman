#ifndef __MOVABLE_H__
#define __MOVABLE_H__

#include <GL/glut.h>
#include <string>

	

class Movable {
	public:
		GLfloat _x;
		GLfloat _y;
		GLfloat _rotate;
		std::string _turn;
		std::string _direction;
		std::string _dirBeforeStop;

	public:
		Movable(){};

		virtual void draw(void){}
		virtual void drawFace(void){}
		void draweyes (bool mode);
		void drawiris(bool mode);
		void draweyebrows(void);
		int move(double step);
		void setPos(GLfloat x, GLfloat y) {
			_x = x; 
			_y = y;
		}
		void setRot(GLfloat rotate) {
			_rotate = rotate;
		}
		void setDirection(std::string str){
			_direction.replace(0,_direction.length(),str);
		}
		void setTurn(std::string str){
			_turn.replace(0,_turn.length(),str);
		}
};

#endif