#include "TheManHimself.h"

TheManHimself* TheManHimself::pacman = 0;

TheManHimself::TheManHimself() : MovingObject(cocos2d::Vec2(733, 255), "theManHimself.png")
{
	score = 0;
	lives = 3;
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

int TheManHimself::getScore()
{
	return score;
}

void TheManHimself::addToScore(int amount)
{
	score += amount;
}

//rotates pacman based on the direction he is moving
void TheManHimself::updateRotation()
{
	switch (moveDirection)
	{
	case Direction::left:
		sprite->setRotation(0);
		break;

	case Direction::up:
		sprite->setRotation(90);
		break;

	case Direction::right:
		sprite->setRotation(180);
		break;

	case Direction::down:
		sprite->setRotation(270);
		break;
	}
}

//update pacman each frame
void TheManHimself::update(float dt)
{
	MovingObject::update(dt);
	updateRotation();
}
