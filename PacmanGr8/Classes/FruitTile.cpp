#include "FruitTile.h"



FruitTile::FruitTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo) : TileBase(a_position)
{
	tileType = Type::fruit;

	sprite = cocos2d::Sprite::create("insertFruitImage.png");
	sprite->setPosition(centerPosition);
	sceneToAddTo->addChild(sprite, 10);
}


FruitTile::~FruitTile()
{
	sprite->removeFromParent();
}

void FruitTile::resolveCollision()
{
}
