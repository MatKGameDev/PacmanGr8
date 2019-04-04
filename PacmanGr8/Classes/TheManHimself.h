#pragma once
#include "MovingObject.h"

class TheManHimself : public MovingObject
{
public:
	~TheManHimself();

	static TheManHimself* pacman; //single pacman instance

	void createPacman();

	void update(float dt);

private:
	TheManHimself();
};