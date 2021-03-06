/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#include "TheManHimself.h"
#include "AudioLibrary.h"

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

int TheManHimself::getLives() const
{
	return lives;
}

int TheManHimself::getScore() const
{
	return score;
}

void TheManHimself::addToScore(int amount)
{
	score += amount;
}
//subtracks one live from the player
void TheManHimself::livesdown()
{
	lives--;
}

void TheManHimself::takeDamage()
{
	lives--;
	sprite->setPosition(cocos2d::Vec2(733, 255));
	AudioLibrary::Death.play();
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
//will make pacman able to eat ghosts 
void TheManHimself::poweredPac(bool powred)
{
	powred = true;
}
//removes pacmans powerd sate
void TheManHimself::notPowerdPac(bool powred)
{
	powred = false;
}
