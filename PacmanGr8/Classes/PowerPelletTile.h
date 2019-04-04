#pragma once
#include "TileBase.h"

class PowerPelletTile : public TileBase
{
public:
	PowerPelletTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo);
	~PowerPelletTile();

	void resolveCollision() override;

private:
	cocos2d::Sprite* sprite;
};

