/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

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
