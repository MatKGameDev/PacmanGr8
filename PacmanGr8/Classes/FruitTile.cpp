/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#include "FruitTile.h"
#include "TheManHimself.h"

const float FruitTile::LIFETIME = 10.0f;
std::vector<FruitTile*> FruitTile::fruitTileList = std::vector<FruitTile*>(); //list containing every fruit tile

FruitTile::FruitTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo, FruitType a_type) : TileBase(a_position)
{
	tileType = Type::fruit;

	setFruit(a_type, sceneToAddTo);

	lifeTimer = LIFETIME; //set timer

	fruitTileList.push_back(this);
}

FruitTile::~FruitTile()
{
	sprite->removeFromParent();
	fruitTileList.pop_back();
}

//ACCESSORS
int FruitTile::getScoreValue() const
{
	return scoreValue;
}

float FruitTile::getLifeTimer() const
{
	return lifeTimer;
}
//end of accessors

//sets the fruit type and corresponding sprite
void FruitTile::setFruit(const FruitType a_type, cocos2d::Scene* sceneToAddTo)
{
	type = a_type;

	if (type == FruitType::apple)
	{
		scoreValue = 400;
		sprite = cocos2d::Sprite::create("apple.png");
	}
	else if (type == FruitType::orange)
	{
		scoreValue = 650;
		sprite = cocos2d::Sprite::create("orange.png");
	}

	sprite->setPosition(centerPosition);
	sceneToAddTo->addChild(sprite, 10);
}

//reduces the life timer of the fruit (should be called each frame and passed dt)
void FruitTile::reduceLifeTimer(const float amount)
{
	lifeTimer -= amount;
}

//checks if the fruit is past its lifetime and performs resolution
bool FruitTile::checkAndResolveExpiry()
{
	if (lifeTimer <= 0.0f)
	{
		replaceWithEmptyTile();
		return true;
	}
	return false;
}

void FruitTile::resolveCollision()
{
	TheManHimself::pacman->addToScore(scoreValue);

	//replace with empty tile
	replaceWithEmptyTile();
}
