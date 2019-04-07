/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#pragma once
#include "TileBase.h"

class PelletTile : public TileBase
{
public:
	PelletTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo);
	~PelletTile();

	static const int scoreValue = 10;
	static int pelletsCollected;

	void resolveCollision() override;

private:
	cocos2d::Sprite* sprite;
};

