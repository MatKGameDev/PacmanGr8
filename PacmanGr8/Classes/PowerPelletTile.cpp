/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#include "PowerPelletTile.h"
#include "EmptyTile.h"
#include "TheManHimself.h"
#include "Ghost.h"

PowerPelletTile::PowerPelletTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo) : TileBase(a_position)
{
	tileType = Type::powerPellet;

	sprite = cocos2d::Sprite::create("powerPellet.png");
	sprite->setPosition(centerPosition);
	sceneToAddTo->addChild(sprite, 10);
}


PowerPelletTile::~PowerPelletTile()
{
	sprite->removeFromParent();
}

void PowerPelletTile::resolveCollision()
{
	TheManHimself::pacman->addToScore(scoreValue); //add score value
	Ghost::setAllGhostsState(Ghost::State::scared);

	//replace with empty tile
	replaceWithEmptyTile();
}
