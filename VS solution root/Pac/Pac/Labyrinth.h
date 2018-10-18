#ifndef __LABYRINTH_H__
#define __LABYTINTH_H__
#pragma once

#include <GL/glut.h>
#include <vector>
#include "Wall.h"
#include "Floor.h"
#include "Food.h"

class Labyrinth {
	std::vector<Wall*> _wall;
	std::vector<Floor*> _floor;
	std::vector<Food*> _food;
	
public:
	Labyrinth(){};
	void create();
	void addWall(Wall *w);
	void addFood(Food *f);
	void addFloor(Floor *f);
	Food getFood(float pacX, float pacY);
	void Labyrinth::deleteBall(float pacX, float pacY);
	bool existBall(float pacX, float pacY);
	void eatBigBall(float pacX, float pacY);
	int Labyrinth::getScore();
	void draw();
};

#endif