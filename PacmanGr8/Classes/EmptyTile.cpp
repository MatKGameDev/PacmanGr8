#include "EmptyTile.h"

EmptyTile::EmptyTile(cocos2d::Vec2 a_position) : TileBase(a_position)
{
	tileType = Type::empty;
}

EmptyTile::~EmptyTile()
{
}
