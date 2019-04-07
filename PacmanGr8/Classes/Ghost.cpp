/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#include "Ghost.h"

std::vector<Ghost*> Ghost::ghostList = std::vector<Ghost*>(); //list containing every ghost

int Ghost::frameCounter = 0;

float Ghost::penTimer = 0.0f;
const float Ghost::MAX_PEN_TIME = 5.0f;

Ghost::Ghost(std::string spriteFilePath) : MovingObject(cocos2d::Vec2(705, 510), spriteFilePath)
{
	isInPen = true;
	ghostList.push_back(this);
}

Ghost::~Ghost()
{
}

//spawns all 4 ghosts onto the scene
void Ghost::spawnAllGhosts(cocos2d::Scene* sceneToAddTo)
{
	Ghost* ghost1 = new Ghost("ghost1.png");
	sceneToAddTo->addChild(ghost1->sprite, 18);

	Ghost* ghost2 = new Ghost("ghost2.png");
	sceneToAddTo->addChild(ghost2->sprite, 18);

	Ghost* ghost3 = new Ghost("ghost3.png");
	sceneToAddTo->addChild(ghost3->sprite, 18);

	Ghost* ghost4 = new Ghost("ghost4.png");
	sceneToAddTo->addChild(ghost4->sprite, 18);

}

void Ghost::removeAllGhosts()
{
	ghostList.clear();
}

void Ghost::removeFromPen()
{
	//remove the ghost from the pen
	sprite->setPosition(cocos2d::Vec2(720, 600));
	isInPen = false;
}

//returns ghost to pen
void Ghost::returnToPen()
{
	sprite->setPosition(cocos2d::Vec2(705, 510));
	isInPen = true;
}

//gets a random direction for the ghost to look
MovingObject::Direction Ghost::getRandomLookDirection()
{
	//1 = up, 2 = down, 3 = left, 4 = right

	int randomNum = rand() % 4 + 1; //random number between 1 and 4

	switch (randomNum)
	{
	case 1:
		if (moveDirection == Direction::down)
			return Direction::left;
		else
			return Direction::up;
		break;

	case 2:
		if (moveDirection == Direction::up)
			return Direction::right;
		else
			return Direction::down;
		break;

	case 3:
		if (moveDirection == Direction::right)
			return Direction::up;
		else
			return Direction::left;
		break;

	case 4:
		if (moveDirection == Direction::left)
			return Direction::down;
		else
			return Direction::right;
		break;
	}
}

//updates the ghost pen
void Ghost::updatePen(const float dt)
{
	penTimer += dt;
	if (penTimer >= MAX_PEN_TIME)
	{
		//check if any ghosts are in the pen
		unsigned int ghostListSize = ghostList.size();
		for (unsigned int i = 0; i < ghostListSize; i++)
		{
			if (ghostList[i]->isInPen)
			{
				ghostList[i]->removeFromPen();
				penTimer = 0.0f;
				break;
			}
		}
	}
}

void Ghost::update(const float dt)
{
	frameCounter++;

	if (frameCounter % 15 == 0) //only update their look direction once every few frames
		lookDirection = getRandomLookDirection();

	MovingObject::update(dt);
}
