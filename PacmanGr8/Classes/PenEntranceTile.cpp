#include "PenEntranceTile.h"



PenEntranceTile::PenEntranceTile(cocos2d::Vec2 a_position) : TileBase(a_position)
{
	tileType = Type::penEntrance;
}


PenEntranceTile::~PenEntranceTile()
{
}

void PenEntranceTile::resolveCollision()
{
}
