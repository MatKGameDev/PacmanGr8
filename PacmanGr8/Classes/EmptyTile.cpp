/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#include "EmptyTile.h"

EmptyTile::EmptyTile(cocos2d::Vec2 a_position) : TileBase(a_position)
{
	tileType = Type::empty;
}

EmptyTile::~EmptyTile()
{
}
