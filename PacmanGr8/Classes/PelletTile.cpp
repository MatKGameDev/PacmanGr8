#include "PelletTile.h"
#include "EmptyTile.h"
#include "TheManHimself.h"

int PelletTile::pelletsCollected = 0;

PelletTile::PelletTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo) : TileBase(a_position)
{
	tileType = Type::pellet;

	sprite = cocos2d::Sprite::create("pellet.png");
	sprite->setPosition(centerPosition);
	sceneToAddTo->addChild(sprite, 10);
}

PelletTile::~PelletTile()
{
	sprite->removeFromParent();
}

void PelletTile::resolveCollision()
{
	TheManHimself::pacman->addToScore(scoreValue); //add score value
	pelletsCollected++; //increment pellets collected

	//replace with empty tile
	replaceWithEmptyTile();
}
