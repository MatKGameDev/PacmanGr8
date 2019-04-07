/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#pragma once
#include "TileBase.h"
class EmptyTile : public TileBase
{
public:
	EmptyTile(cocos2d::Vec2 a_position);
	~EmptyTile();

	void resolveCollision() override {};
};