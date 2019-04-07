#pragma once
#ifndef LEVEL1_H
#define LEVEL1_H

#include "cocos2d.h"

using namespace cocos2d;

class Level1 : public cocos2d::Scene
{
public:
	CREATE_FUNC(Level1);
	static Scene* createScene();

	bool init();
	void initTilemap();
	void initSprites();
	void initObjects();
	void initKeyboardListener();

	//keyboard callbacks
	void keyDownCallback(EventKeyboard::KeyCode keyCode, Event* event);

	void update(const float dt);
	void updateObjects(const float dt);
	void updateFruitSpawns();
	void checkAndResolveGhostOnPacmanCollision();

private:
	Director* director;
	EventListenerKeyboard* keyboardListener;

	bool isFirstFruitSpawned;
	bool isSecondFruitSpawned;
	//wether pacman is powerd or not
	bool powred = false;
	//counts how long pac-man has the powred effect 
	float powerTime = 0.0f;
};
#endif