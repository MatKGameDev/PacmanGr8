#include "TileBase.h"

const cocos2d::Vec2 TileBase::MIN_POSITION = cocos2d::Vec2(300, 30);   //the bottom left position of the first TileBase
const cocos2d::Vec2 TileBase::MAX_POSITION = cocos2d::Vec2(1140, 960); //the bottom left position of the last TileBase

std::vector<TileBase*> TileBase::tileList = std::vector<TileBase*>(); //list containing every TileBase

//constructor
TileBase::TileBase(cocos2d::Vec2 a_position, int height, int width)
{
	bottomLeftPosition = a_position + MIN_POSITION;
	hitbox.setRect(bottomLeftPosition.x, bottomLeftPosition.y, width, height);
	centerPosition = bottomLeftPosition + cocos2d::Vec2(height / 2, width / 2);

	tileType = Type::empty; //initialize each TileBase to empty (if it's not actually empty, the TileBase's specific constructor will set it properly)

	tileList.push_back(this);
}

TileBase::~TileBase()
{
}

//removes all tiles from each TileBase vector
void TileBase::deleteAllTiles()
{
	tileList.clear();
}

//resolves any collision on tiles from the given point
void TileBase::resolveCollisionsOnPoint(cocos2d::Vec2 pointToCheck)
{
	TileBase* tileCollidedWith = getTileAt(pointToCheck);

	if (tileCollidedWith != nullptr)
		tileCollidedWith->resolveCollision();
}

//gets the TileBase at the specified location (if possible)
TileBase * TileBase::getTileAt(cocos2d::Vec2 a_position)
{
	unsigned int tileListSize = tileList.size();
	for (unsigned int i = 0; i < tileListSize; i++)
	{
		if (tileList[i]->containsPoint(a_position))
			return tileList[i];
	}

	return nullptr;
}

//checks if the point given is within the TileBase's bounds
bool TileBase::containsPoint(cocos2d::Vec2 point)
{
	if (hitbox.containsPoint(point))
		return true;

	return false;
}

//ACCESSORS
cocos2d::Vec2 TileBase::getBottomLeftPosition() const
{
	return bottomLeftPosition;
}

cocos2d::Vec2 TileBase::getCenterPosition() const
{
	return centerPosition;
}

cocos2d::Rect TileBase::getHitbox() const
{
	return hitbox;
}

TileBase::Type TileBase::getType() const
{
	return tileType;
}
