#pragma once
#include "TileBase.h"

class WallTile : public TileBase
{
public:
	WallTile(cocos2d::Vec2 a_position);
	~WallTile();

	void resolveCollision() override;
};