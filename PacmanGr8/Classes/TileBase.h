/*
	OOP Pacman Group 8
		Mathew Kostrzewa        - 100591924
		Michelle Escobar Cubias - 100709888 -
		Sean Birket             - 100704214
		Charley Fai             - 100698666
		Devin Fitzpatrick       - 100709082
*/

#pragma once
#ifndef TILE_H
#define TILE_H

#include "cocos2d.h"

class TileBase
{
public:
	enum Type
	{
		empty,
		pellet,
		powerPellet,
		wall,
		penEntrance,
		fruit
	};

	TileBase(cocos2d::Vec2 a_position, int height = 30, int width = 30);
	virtual ~TileBase();

	static const cocos2d::Vec2 MIN_POSITION;
	static const cocos2d::Vec2 MAX_POSITION;

	static std::vector<TileBase*> tileList;

	static void deleteAllTiles();
	void replaceWithEmptyTile();

	static void resolveCollisionsOnPoint(cocos2d::Vec2 pointToCheck);
	static TileBase* getTileAt(cocos2d::Vec2 a_position);
	bool containsPoint(cocos2d::Vec2 point);

	virtual void resolveCollision() = 0;

	cocos2d::Vec2 getBottomLeftPosition() const;
	cocos2d::Vec2 getCenterPosition() const;
	cocos2d::Rect getHitbox() const;
	Type getType() const;

protected:
	cocos2d::Vec2 bottomLeftPosition;
	cocos2d::Vec2 centerPosition;
	cocos2d::Rect hitbox;

	Type tileType;
};

#endif