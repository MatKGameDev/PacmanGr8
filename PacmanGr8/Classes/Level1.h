/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 - 
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

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
	static void preloadAudio();

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
};
#endif