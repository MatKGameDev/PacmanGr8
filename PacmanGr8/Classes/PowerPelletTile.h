#pragma once
#include "TileBase.h"

class PowerPelletTile : public TileBase
{
public:
	PowerPelletTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo);
	~PowerPelletTile();

	static const int scoreValue = 50;

	void resolveCollision() override;

private:
	cocos2d::Sprite* sprite;
};

