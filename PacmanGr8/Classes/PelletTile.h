#pragma once
#include "TileBase.h"

class PelletTile : public TileBase
{
public:
	PelletTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo);
	~PelletTile();

	static const int scoreValue = 10;
	static int pelletsCollected;

	void resolveCollision() override;

private:
	cocos2d::Sprite* sprite;
};

