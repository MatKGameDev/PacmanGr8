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

class Ghost : public MovingObject
{
public:
	enum State
	{
		normal,
		scared
	};

	Ghost(std::string spriteFilePath);
	~Ghost();

	static std::vector<Ghost*> ghostList;

	static void spawnAllGhosts(cocos2d::Scene* sceneToAddTo);
	static void removeAllGhosts();

	static int frameCounter;
	static float penTimer;
	static const float MAX_PEN_TIME;
	static const float MAX_SCARED_TIME;

	void removeFromPen();
	void returnToPen();

	void setState(const State newState);
	static void setAllGhostsState(const State newState);
	
	State getCurrentState() const;

	Direction getRandomLookDirection();
	static void updatePen(const float dt);
	void update(const float dt);

private:
	bool isInPen;
	State currentState;
	float scaredTimer;
	std::string originalSprite;
};

