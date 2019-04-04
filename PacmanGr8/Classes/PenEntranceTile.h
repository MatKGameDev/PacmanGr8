#pragma once
#include "TileBase.h"

class PenEntranceTile : public TileBase
{
public:
	PenEntranceTile(cocos2d::Vec2 a_position);
	~PenEntranceTile();

	void resolveCollision() override;
};

