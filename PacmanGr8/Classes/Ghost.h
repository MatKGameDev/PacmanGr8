#pragma once
#include "MovingObject.h"

class Ghost : public MovingObject
{
public:
	Ghost(std::string spriteFilePath);
	~Ghost();

	static std::vector<Ghost*> ghostList;

	static void spawnAllGhosts(cocos2d::Scene* sceneToAddTo);
	static void removeAllGhosts();

	static int frameCounter;
	static float penTimer;
	static const float MAX_PEN_TIME;

	void removeFromPen();
	void returnToPen();

	Direction getRandomLookDirection();
	static void updatePen(const float dt);
	void update(const float dt);

private:
	bool isInPen;
};

