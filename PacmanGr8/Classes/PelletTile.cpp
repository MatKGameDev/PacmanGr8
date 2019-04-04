#include "PelletTile.h"



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
}
