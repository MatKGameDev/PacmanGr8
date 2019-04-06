#pragma once
#include "TileBase.h"
class EmptyTile : public TileBase
{
public:
	EmptyTile(cocos2d::Vec2 a_position);
	~EmptyTile();

	void resolveCollision() override {};
};