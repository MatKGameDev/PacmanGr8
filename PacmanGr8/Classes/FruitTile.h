#pragma once
#include "TileBase.h"

class FruitTile : public TileBase
{
public:
	enum FruitType
	{

	};

	FruitTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo);
	~FruitTile();

	void resolveCollision() override;

private:
	cocos2d::Sprite* sprite;
};

