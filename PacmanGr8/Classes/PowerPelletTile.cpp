#include "PowerPelletTile.h"
#include "EmptyTile.h"
#include "TheManHimself.h"

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

	//replace with empty tile
	replaceWithEmptyTile();
}
