#if defined (__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#ifndef M_PI
	#define M_PI 3.14159265
#endif

#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "glbmp.h"
#include "Labyrinth.h"
#include "Pacman.h"
#include "Ghost.h"
#include "AuxFuncs.h"

//Objectos
Labyrinth *l = new Labyrinth();
Pacman *p = new Pacman();
std::vector<Ghost*> ghosts;
//variaveis para o elapsed time
double step;
double now;
double delta;
double lastTime = 0;
double record = 0;
bool Credits = false;
//
int alreadyScared = 0;
int queued = 0;
bool pacmanLife = true, controle = false;
int lives = 3;
// Tamanho da janela de visualizaÁ„o
GLfloat w, h;
// R·cio de reshape 
GLfloat ratio = 0;
// C‚mara activa
GLint nCam = 1;
GLint nLight = 3;
//Guarda a string do score
char strScore[10];
GLuint particleTex;
#define MAX_PARTICULAS  1500
#define frand()			((float)rand()/RAND_MAX)

//estrutura de cada particula

typedef struct {
	float	life;		// vida
	float	fade;		// fade
	float	r, g, b;    // color
	GLfloat x, y, z;    // posição
	GLfloat vx, vy, vz; // velocidade 
    GLfloat ax, ay, az; // aceleração
} Particle;

Particle particula[MAX_PARTICULAS];

void iniParticulas(void)
{
 GLfloat v, theta, phi;
 int i;

 for(i=0; i<MAX_PARTICULAS; i++)
    {
	v = 0.8*frand()+0.2;
    phi = frand()*M_PI;
    theta = 2.0*frand()*M_PI;
		particula[i].x =  p->_x;//x      
		particula[i].y =  p->_y;//y
		particula[i].z =  0.75;//z      

		particula[i].vx =  v * cos(theta) * sin(phi);//x      
		particula[i].vy =  v * sin(theta) * sin(phi);//y
		particula[i].vz =  v * cos(phi);//z 

		particula[i].ax =  0.01f;//x
		particula[i].ay =  0.0f;//y 
		particula[i].az = -0.15f;//z

		particula[i].r = 0.8;//x
		particula[i].g = 0.5;//y 
		particula[i].b = 0.0;//z  
	
	/* tom amarelado que vai ser multiplicado pela textura que varia entre branco e preto */
	particula[i].r = 0.882f;
	particula[i].g = 0.552f;	
	particula[i].b = 0.211f;

	particula[i].life = 1.0f;		/* vida inicial */                
	particula[i].fade = 0.00005f;	    /* step de decrÈscimo da vida para cada iteraÁ„o */
	}
}

void doParticles (void){  
	int i;
	if(pacmanLife == false){
		for( i = 0; i<MAX_PARTICULAS; i++){
			if(particula[i].z > 0){
					GLfloat ambientMaterial[]  = { 1, 0.7, 0, 1.0f };
	GLfloat diffuseMaterial[]	= { 1, 0.7, 0, 1.0f };
	GLfloat especularMaterial[] = { 0.6,0.6,0.6, 1.0f };
	GLfloat shininess = 125;
				 
				glPointSize(1.5);
				glBegin(GL_POINTS);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especularMaterial);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
				glVertex3f(particula[i].x, particula[i].y, particula[i].z);
				glEnd();
			}	              
		}
	}
}


void iterate(int value)
{
	int i;
	float h; 

	/* MÈtodo de Euler de integraÁ„o de eq. diferenciais ordin·rias 
		h representa o step de tempo; dv/dt = a; dx/dt = v; e conhecem-se os valores iniciais de x e v */

	h=0.125f;
	for (i=0; i<MAX_PARTICULAS; i++)
	{
		particula[i].x += (h*particula[i].vx);
		particula[i].y += (h*particula[i].vy);
		particula[i].z += (h*particula[i].vz);
		particula[i].vx += (h*particula[i].ax);
		particula[i].vy += (h*particula[i].ay);
		particula[i].vz += (h*particula[i].az);
		particula[i].life -= particula[i].fade;
	}
 glutPostRedisplay();
 glutTimerFunc(40,iterate,1);
}

void doHearts(float x ){
	glPushMatrix();
		glTranslatef(x,16.8,0);
		glScalef(0.15,0.15,0.15);
		glColor3f(0.8,0,0);
		glBegin(GL_POLYGON); 
			glVertex2f(0,0);
			glVertex2f(5,5); 
			glVertex2f(2.5,7.5);
			glVertex2f(0,5);
			glVertex2f(-2.5,7.5);
			glVertex2f(-5,5); 
		glEnd();
	glPopMatrix();
}
void doghosts(float x){
	Ghost *g = new Ghost(1,1,1);
	glPushMatrix();
		glTranslatef(x,16.8,0);
		glScalef(0.15,0.15,0.15);
		g->draw();
		glEnd();
	glPopMatrix();
}
void setRatio(void){
	if(w >= h)
		 ratio = (float) w/h;
	else ratio = (float) h/w;
}

void myReshape(GLsizei width, GLsizei height){  
	w = width;   
	h = height;
	setRatio();
}

void setViewport(void){
	glViewport(0,0,w,h);
}

void setCam(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(nCam == 1) {
		glMatrixMode(GL_MODELVIEW);
	    glLoadIdentity();
		if( w >= h)
			glOrtho(ratio*-19.0f, ratio*19.0f, -19.0f, 19.0f, -19.0f, 19.0f);
		else glOrtho(-19.0f, 19.0f, ratio*-19.0f, ratio*19.0f, -19.0f, 19.0f);
	}
	else{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(65,ratio,1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(p->_x ,p->_y - 8.5,6,p->_x,p->_y+1 ,1,0,1,2);
	}
}


void drawGhosts(void){
	int i;

	for(i = 0; i < ghosts.size(); i++){
		if(!ghosts.at(i)->isDead()){
			ghosts.at(i)->eyeAngle(p->_x,p->_y);
			ghosts.at(i)->draw();
		}
	}
}

void drawAll(){
	l->draw();
	if(pacmanLife){
	p->draw();
	}
	drawGhosts();
}

void ghostTimer(int value){
	int i;

	if(alreadyScared == 0){
		for(i = 0; i < ghosts.size(); i++){
			ghosts.at(i)->normal();
		}
	}
	else alreadyScared--;
}

void scareGhost(){
	int i;

	if(ghosts.at(0)->isScared())
		alreadyScared++;

	for(i = 0; i < ghosts.size(); i++)
		ghosts.at(i)->scared();
	glutTimerFunc(10000,ghostTimer,1);
}

void TextOutput(int x, int y, char *string){
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  glColor3f(0.8, 0.8, 0.8);
  for (i = 0; i < len; i++)
  {
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
}

void switchToOrtho(){
	glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
	glOrtho(ratio*-19.0f, ratio*19.0f, -19.0f, 19.0f, -19.0f, 19.0f);      
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void switchBackToPerspective(){
	glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
   // glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void unlockGhosts(int value){
	int i;
	bool found = false;
	Ghost *auxGhost;

	for(i = 0; i < ghosts.size(); i++){
		if(ghosts.at(i)->isCaged()){
			if(!found){
				auxGhost = ghosts.at(i);
				found = true;
			}
			else if(ghosts.at(i)->getQueue() < auxGhost->getQueue())
				auxGhost = ghosts.at(i);
		}
	}

	if(found)
		auxGhost->unlock();

	for(i = 0; i < ghosts.size(); i++){
		if(!ghosts.at(i)->isFree() && !ghosts.at(i)->isDead()){
			glutTimerFunc(10000,unlockGhosts,1);
			break;
		}
	}	
}

void ghostsMove(double step){
	int i;

	for(i = 0; i < ghosts.size(); i++){
		if(!ghosts.at(i)->isDead()){
			if(!ghosts.at(i)->isCaged()){
				if(ghosts.at(i)->isScared())
					ghosts.at(i)->move(2*step/3);
				else ghosts.at(i)->move(step);
				ghosts.at(i)->nextTurn(step);
			}
			else {
				ghosts.at(i)->move(step);
				ghosts.at(i)->moveOnCage(step);
			}
		}
	}
}

void textOutput(void){
	int time; 
	if(l->getScore() < 2440){
		TextOutput(-10, 24, ".");
		if(lives >= 0){
			TextOutput(5, 17, "Score:");
			sprintf (strScore, "%d", l->getScore());
			TextOutput(10, 17, strScore);
		}
		if(lives > 0)
			TextOutput(-12, 17, "Lives: ");
	}
	if(!Credits){
		if(lives == 3){
			doHearts(-7.5);
			doHearts(-6.0);
			doHearts(-4.5);
		}
		else if(lives == 2){
			doHearts(-7.5);
			doHearts(-6.0);
		}
		else if(lives == 1){
			doHearts(-7.5);
		}
		else if(lives == 0){
			if(nCam == 2){
				TextOutput(-4, 13, "!Divine Intervention!");
			}
			else{
				TextOutput(-6, 16, "!Divine Intervention!");
			}
		}
		else { TextOutput(-10, 24, ".");
			if(nCam == 2){
				TextOutput(-4, 13, "...Reset in Peace little noob...");
				}
				else{
					TextOutput(-6, 16, "...Reset in Peace little noob...");
				}
		}
	}
	if(l->getScore() >= 2440){
		TextOutput(-10, 24, ".");
		time = glutGet(GLUT_ELAPSED_TIME);
		if(!Credits){
			Credits = true;
			record = time;
		}
		else if(time - record >= 37500){
			if(nCam == 2){
				TextOutput(-8, 13, "THE END");
			}
			else{
				TextOutput(-6, 16, "THE END");
			}			
		}
		else if(time - record >= 35000){
			if(nCam == 2){
				TextOutput(-8, 13, "IST Graphical Computation");
			}
			else{
				TextOutput(-6, 16, "IST Graphical Computation");
			}			
		}
		else if(time - record >= 32000){
			if(nCam == 2){
				TextOutput(-8, 13, "Ricardo Neves and Fabio Antunes");
			}
			else{
				TextOutput(-6, 16, "Ricardo Neves and Fabio Antunes");
			}			
		}
		else if(time - record >= 30000){
			if(nCam == 2){
				TextOutput(-8, 13, "And his assistants");
			}
			else{
				TextOutput(-6, 16, "And his assistants");
			}			
		}
		else if(time - record >= 20000){
			if(nCam == 2){
				TextOutput(-8, 13, "ANDRE NUNES");
			}
			else{
				TextOutput(-6, 16, "ANDRE NUNES");
			}			
		}
		else if(time - record >= 10000){
			if(nCam == 2){
				TextOutput(-8, 13, "The Brilliant mind");
			}
			else{
				TextOutput(-6, 16, "The Brilliant mind");
			}			
		}
		else if(time - record >= 5000){
			if(nCam == 2){
				TextOutput(-8, 13, "Made by");
			}
			else{
				TextOutput(-6, 16, "Made by");
			}			
		}
	}
}

void lightSet(int nLight){

	GLfloat _amb    []		 = {  0.2, 0.2, 0.2, 1.0f};
	GLfloat _zeroAmb[]		 = {  0.0f,  0.0f,  0.0f,  1.0f};
	GLfloat ambientLight[]   = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight[]	 = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specularLight[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[]		 = { 0.0f, 0.0f, 1.0f, 0 };
	GLfloat position1[]		 = { p->_x,p->_y , 2.5f, 1.0f };
	GLfloat spotDirection1[] = {sin(p->_rotate*3.14/180),-cos(p->_rotate*3.14/180),-0.7,1};

	if( nLight == 3){
		glLightModelfv( GL_LIGHT_MODEL_AMBIENT, _amb);
		glDisable(GL_LIGHT1);
		glEnable(GL_LIGHT0);
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.5);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
		glLightfv(GL_LIGHT0, GL_POSITION, position);
	}
	else{
		glLightModelfv( GL_LIGHT_MODEL_AMBIENT, _zeroAmb);
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.5);
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
		glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
		glLightfv(GL_LIGHT1, GL_POSITION, position1);
		glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,27.0);

		if(p->_direction.compare("up") == 0){
			spotDirection1[0] = 0;
			spotDirection1[1] = 1;
		}
		if(p->_direction.compare("right") == 0){
			spotDirection1[0] = 1;
			spotDirection1[1] = 0;
		}
		if(p->_direction.compare("left") == 0){
			spotDirection1[0] = -1;
			spotDirection1[1] = 0;
		}
		if(p->_direction.compare("down") == 0){
			spotDirection1[0] = 0;
			spotDirection1[1] = -1;
		}
		glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotDirection1);
		glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,2.0);

	}
}

void rebornPac(int value){
		p->_x = 0;
		p->_y = -9;
		p->_direction = "left";
		p->_turn = "left";
		pacmanLife = true;
		lives--;
		controle = false;
		if(lives <= 0)
			p->dI();
}

void rebornGhost(int value){
	int i;

	for(i = 0; i < ghosts.size(); i++){
		if(ghosts.at(i)->isDead()){
			ghosts.at(i)->revive();
			break;
		}	
	}
	glutTimerFunc(10000,unlockGhosts,1);
}


void colision(void){
	int i;
	if(controle == false){
		for(i = 0; i < ghosts.size(); i++){
			if(((ghosts.at(i)->_x >= (p->_x - 0.75)) && (ghosts.at(i)->_x <= (p->_x + 0.75))) && ((ghosts.at(i)->_y >= (p->_y - 0.75)) && (ghosts.at(i)->_y <= (p->_y + 0.75)))){
				if(ghosts.at(i)->isScared()){
					glutTimerFunc(5000,rebornGhost,1);
					ghosts.at(i)->die();
					ghosts.at(i)->setQueue(queued++);
				}
				else{
					pacmanLife = false;
					iniParticulas();
					controle = true;
					if(lives > 0)
						glutTimerFunc(5000,rebornPac,1);
					else if(lives == 0){
						lives --;
					}
				}
			}
		}
	}
}

void myDisplay(void){
	float tempX = adjust(p->_x);
	float tempY = adjust(p->_y);
	int x = convertePacX(tempX, tempY);
	int y = convertePacY(tempX, tempY);

	now = glutGet(GLUT_ELAPSED_TIME);
	delta = now - lastTime;
	step = delta/150;
	lastTime = now;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable (GL_DEPTH_TEST);
	switchToOrtho();
	textOutput();
	switchBackToPerspective();
	setViewport();
	setCam();
	lightSet(nLight);
	drawAll();
	l->deleteBall(tempX,tempY);
	if(pathFood[x][y] == 2 && l->existBall(p->_x,p->_y)){
		scareGhost();
		l->eatBigBall(p->_x,p->_y);
	}
	if(pacmanLife)
		p->move(step);
	else doParticles();
	ghostsMove(step);
	
	colision();
	glutSwapBuffers();
}

void idle(){
	if(nLight == 4){
		lightSet(nLight);
		glutPostRedisplay();
	}
	else{
		//lightSet(nLight);
		glutPostRedisplay();
	}
	
}

void special(int key, int x, int y){
    switch(key) {
		case GLUT_KEY_LEFT:
			p->setTurn("left");
	    break;
        
		case GLUT_KEY_RIGHT:
			p->setTurn("right");
	    break;
       
		case GLUT_KEY_UP:
			p->setTurn("up");
	    break;
        
	    case GLUT_KEY_DOWN:
			p->setTurn("down");
	    break;   
	}
}

void init(){
	Ghost *g1 = new Ghost(1,0,1);
	Ghost *g2 = new Ghost(1,0,0);
	Ghost *g3 = new Ghost(0,1,0);
	g1->setPos(-1.6,0);
	g1->setDirection("right");
	g1->setQueue(queued++);
	g2->setPos(0,3);
	g2->setDirection("left");
	g2->unlock();
	g2->gotOut();
	g3->setPos(1.6,0);
	g3->setDirection("left");
	g3->setQueue(queued++);
	ghosts.push_back(g1);
	ghosts.push_back(g2);
	ghosts.push_back(g3);
	glutTimerFunc(10000,unlockGhosts,1);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);	
	glEnable(GL_SMOOTH);
	//lightSet(nLight);
	lastTime = glutGet(GLUT_ELAPSED_TIME);
}

void keyboard(unsigned char key, int x, int y){
	switch(key) {
		case '1':
				nCam = 1;
	    break;
	    case '2':
				nCam = 2;
	    break;
		case '3':
			nLight = 3;
			lightSet(nLight);
		break;

		case '4':
			nLight = 4;
			lightSet(nLight);
		break;
	}
}

int main(int argc, char *argv[]){
	l->create();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (-1, -1); 
    glutCreateWindow("Pacman 3D");
	init();
	glutTimerFunc(33,iterate,1);
	glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutMainLoop();
}
