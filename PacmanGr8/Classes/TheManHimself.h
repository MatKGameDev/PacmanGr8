#pragma once
#include "MovingObject.h"

class TheManHimself : public MovingObject
{
public:
	~TheManHimself();

	static TheManHimself* pacman; //single pacman instance

	void createPacman();

	int getScore();
	void addToScore(int amount);

	void updateRotation();
	void update(float dt);

private:
	TheManHimself();

	int score;
	int lives;
};