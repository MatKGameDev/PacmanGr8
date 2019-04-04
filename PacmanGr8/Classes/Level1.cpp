#include "Level1.h"
#include "WallTile.h"
#include "PenEntranceTile.h"
#include "FruitTile.h"
#include "PelletTile.h"
#include "PowerPelletTile.h"
#include "TheManHimself.h"
#include "Ghost.h"

Scene * Level1::createScene()
{
	Scene* scene = Level1::create();
	return scene;
}

//initialize scene
bool Level1::init()
{
	if (!Scene::init())
		return false;

	director = Director::getInstance();
	//Setting the default animation rate for the director
	director->setAnimationInterval(1.0f / 60.0f);

	initTilemap();
	initSprites();

	scheduleUpdate();

	return true;
}

//initialize tilemap on load
void Level1::initTilemap()
{
	//load tilemap
	cocos2d::TMXTiledMap* levelTileMap = TMXTiledMap::create("level1.tmx");
	levelTileMap->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	levelTileMap->setPosition(300, 30);
	addChild(levelTileMap, 1);

	//create layers from the TMX
	cocos2d::TMXLayer* wallLayer = levelTileMap->getLayer("walls");
	cocos2d::TMXLayer* penEntranceLayer = levelTileMap->getLayer("wallsButOnAnotherLayer");
	cocos2d::TMXLayer* powerPelletLayer = levelTileMap->getLayer("powerPellets");
	cocos2d::TMXLayer* pelletLayer = levelTileMap->getLayer("pellets");

	//iterate through each tile
	unsigned int tileMapWidth = levelTileMap->getMapSize().width;   //map width
	unsigned int tileMapHeight = levelTileMap->getMapSize().height; //map height
	for (unsigned int x = 0; x < tileMapWidth; x++)       //width of map grid
	{
		for (unsigned int y = 0; y < tileMapHeight; y++)  //height of map grid
		{
			//check for walls
			cocos2d::Sprite* currentTile = wallLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
				WallTile* newWallTile = new WallTile(currentTile->getPosition());

			//check for pen entrance tiles
			currentTile = penEntranceLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
				PenEntranceTile* newPenEntranceTile = new PenEntranceTile(currentTile->getPosition());

			//check for power pellets
			currentTile = powerPelletLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
				PowerPelletTile* newPowerPellet = new PowerPelletTile(currentTile->getPosition(), this);

			//check for pellets
			currentTile = pelletLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
				PelletTile* newPellet = new PelletTile(currentTile->getPosition(), this);
		}
	}
}

//initialize all starting sprites on load
void Level1::initSprites()
{
	//add controls image
	Sprite* controlsImage = Sprite::create("controls.png");
	controlsImage->setPosition(Vec2(1550, 500));
	controlsImage->setScale(2.0f);
	this->addChild(controlsImage, 1);

	//add pacman
	this->addChild(TheManHimself::pacman->getSprite(), 20);
}

void Level1::update(float dt)
{
	TheManHimself::pacman->update(dt);
}