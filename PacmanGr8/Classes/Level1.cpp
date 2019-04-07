#include "Level1.h"
#include "WallTile.h"
#include "PenEntranceTile.h"
#include "FruitTile.h"
#include "PelletTile.h"
#include "PowerPelletTile.h"
#include "EmptyTile.h"
#include "TheManHimself.h"
#include "Ghost.h"
#include "Audio.h"
#include "AudioLibrary.h"

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
	initObjects();
	initKeyboardListener();

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
			bool isTileSet = false;

			//check for walls
			cocos2d::Sprite* currentTile = wallLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
			{
				WallTile* newWallTile = new WallTile(currentTile->getPosition());
				isTileSet = true;
			}

			//check for pen entrance tiles
			currentTile = penEntranceLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
			{
				PenEntranceTile* newPenEntranceTile = new PenEntranceTile(currentTile->getPosition());
				isTileSet = true;
			}

			//check for power pellets
			currentTile = powerPelletLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
			{
				PowerPelletTile* newPowerPellet = new PowerPelletTile(currentTile->getPosition(), this);
				isTileSet = true;
			}

			//check for pellets
			currentTile = pelletLayer->getTileAt(Vec2(x, y));
			if (currentTile != NULL)
			{
				PelletTile* newPellet = new PelletTile(currentTile->getPosition(), this);
				isTileSet = true;
			}

			//if there's no tile set for the current location on the map, set an empty tile
			if (!isTileSet)
			{
				EmptyTile* newEmpty = new EmptyTile(Vec2(x * 30, 900 - (y * 30)));
			}
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

	//add empty tiles for padding on the sides when teleporting
	EmptyTile* newEmptyTile = new EmptyTile(Vec2(840, 480));
	EmptyTile* newEmptyTile2 = new EmptyTile(Vec2(-30, 480));
}

void Level1::initObjects()
{
	PelletTile::pelletsCollected = 0; //reset pellets collected
	isFirstFruitSpawned = false;
	isSecondFruitSpawned = false;

	Ghost::spawnAllGhosts(this);
}

void Level1::initKeyboardListener()
{
	//create the keyboard listener
	keyboardListener = EventListenerKeyboard::create();

	//setting up callbacks
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Level1::keyDownCallback, this);

	//add the keyboard listener to the dispatcher
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

//keyboard callback for user input
void Level1::keyDownCallback(EventKeyboard::KeyCode keyCode, Event * event)
{
	//set look direction based on directional key pressed
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		TheManHimself::pacman->setLookDirection(MovingObject::Direction::up);
		break;

	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		TheManHimself::pacman->setLookDirection(MovingObject::Direction::down);
		break;

	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		TheManHimself::pacman->setLookDirection(MovingObject::Direction::left);
		break;

	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		TheManHimself::pacman->setLookDirection(MovingObject::Direction::right);
		break;
	}
}

void Level1::update(const float dt)
{
	updateObjects(dt);

	updateFruitSpawns();

	checkAndResolveGhostOnPacmanCollision();
}

//updates all objects
void Level1::updateObjects(const float dt)
{
	TheManHimself::pacman->update(dt); //update pacman

	TileBase::resolveCollisionsOnPoint(TheManHimself::pacman->getCenterPosition()); //update pacman->tiles collision

	Ghost::updatePen(dt); //update ghost pen

	//update ghosts
	unsigned int ghostListSize = Ghost::ghostList.size();
	for (unsigned int i = 0; i < ghostListSize; i++)
		Ghost::ghostList[i]->update(dt);

	//update fruits and check for expiries
	unsigned int fruitListSize = FruitTile::fruitTileList.size();
	for (unsigned int i = 0; i < fruitListSize; i++)
	{
		FruitTile::fruitTileList[i]->reduceLifeTimer(dt);
		if (FruitTile::fruitTileList[i]->checkAndResolveExpiry())
			break; //break if a fruit is expiry
	}
}

//checks for any fruit spawns
void Level1::updateFruitSpawns()
{
	if (PelletTile::pelletsCollected == 70 && !isFirstFruitSpawned)
	{
		delete (TileBase::getTileAt(Vec2(390, 390))); //delete existing tile
		FruitTile* newApple = new FruitTile(Vec2(390, 390), this, FruitTile::FruitType::apple);
		isFirstFruitSpawned = true;
	}
	else if (PelletTile::pelletsCollected == 170 && !isSecondFruitSpawned)
	{
		delete (TileBase::getTileAt(Vec2(390, 390))); //delete existing tile
		FruitTile* newOrange = new FruitTile(Vec2(390, 390), this, FruitTile::FruitType::orange);
		isSecondFruitSpawned = true;
	}
}

void Level1::checkAndResolveGhostOnPacmanCollision()
{
	unsigned int ghostListSize = Ghost::ghostList.size();
	for (unsigned int i = 0; i < ghostListSize; i++)
	{
		//check if the ghost and pacman are on the same tile
		if (TileBase::getTileAt(Ghost::ghostList[i]->getCenterPosition()) == TileBase::getTileAt(TheManHimself::pacman->getCenterPosition()))
		{
			//collision!

		}
	}
}
