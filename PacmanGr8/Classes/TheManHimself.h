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
	//changing lives
	void livesdown();
	void updateRotation();
	void update(float dt);
	//pacmans powerd sate were he can eat ghost
	void poweredPac(bool powred);
	//removes pacmans powerd state
	void notPowerdPac(bool powred);
private:
	TheManHimself();

	int score;
	int lives;
	
};