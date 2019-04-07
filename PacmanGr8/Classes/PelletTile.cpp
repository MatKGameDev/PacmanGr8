/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#include "PelletTile.h"
#include "EmptyTile.h"
#include "TheManHimself.h"
#include "AudioLibrary.h"

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
	AudioLibrary::Chomp.play();
	TheManHimself::pacman->addToScore(scoreValue); //add score value
	pelletsCollected++; //increment pellets collected

	//replace with empty tile
	replaceWithEmptyTile();
}
