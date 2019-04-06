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
	void initKeyboardListener();

	//keyboard callbacks
	void keyDownCallback(EventKeyboard::KeyCode keyCode, Event* event);

	void update(const float dt);
	void updateObjects(const float dt);

private:
	Director* director;
	EventListenerKeyboard* keyboardListener;
};
#endif