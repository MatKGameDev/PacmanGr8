/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#pragma once
#include "MovingObject.h"

class TheManHimself : public MovingObject
{
public:
	~TheManHimself();

	static TheManHimself* pacman; //single pacman instance

	void createPacman();

	int getLives() const;
	int getScore() const;
	void addToScore(int amount);

	void takeDamage();

	void updateRotation();
	void update(float dt);

private:
	TheManHimself();

	int score;
	int lives;
};