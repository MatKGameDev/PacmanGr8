#pragma once
#include "cocos2d.h"

class MovingObject
{
public:
	enum Direction
	{
		left,
		right,
		up,
		down
	};

	MovingObject(cocos2d::Vec2 position, std::string spriteFilePath);
	~MovingObject();

	static const cocos2d::Vec2 BASE_VELOCITY;

	void setVelocity(const cocos2d::Vec2 newVelocity);
	void setLookDirection(const Direction newDirection);
	void setMoveDirection(const Direction newDirection);

	cocos2d::Vec2 getVelocity() const;
	cocos2d::Sprite* getSprite() const;
	cocos2d::Vec2 getCenterPosition() const;
	float getLeftSidePosition() const;
	float getRightSidePosition() const;
	float getTopPosition() const;
	float getBottomPosition() const;

	Direction getLookDirection() const;
	Direction getMoveDirection() const;

	float getWidth() const;
	float getHeight() const;

	void centerOnCurrentTile();

	void updateLookDirection();
	void updateMoveDirection();
	void checkForOutOfBounds();
	virtual void update(const float dt);

protected:
	cocos2d::Vec2 velocity;

	cocos2d::Sprite* sprite;

	float width;
	float height;

	Direction lookDirection;
	Direction moveDirection;
};

