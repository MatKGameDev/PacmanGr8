#include "TheManHimself.h"

TheManHimself* TheManHimself::pacman = 0;

TheManHimself::TheManHimself() : MovingObject(cocos2d::Vec2(735, 255), "theManHimself.png")
{
}

TheManHimself::~TheManHimself()
{
}

//singleton class
void TheManHimself::createPacman()
{
	if (!pacman)
		pacman = new TheManHimself;
}

//update pacman each frame
void TheManHimself::update(float dt)
{
	MovingObject::updatePhysics(dt);
}
