#include "WallTile.h"



WallTile::WallTile(cocos2d::Vec2 a_position) : TileBase(a_position)
{
	tileType = Type::wall;
}


WallTile::~WallTile()
{
}

void WallTile::resolveCollision()
{
}
