#include "MovingObject.h"

MovingObject::MovingObject(cocos2d::Vec2 position, std::string spriteFilePath)
{
	//create sprite and set initial values
	sprite = cocos2d::Sprite::create(spriteFilePath);
	sprite->setPosition(cocos2d::Vec2(position.x, position.y));
	width = sprite->getBoundingBox().size.width;
	height = sprite->getBoundingBox().size.height;

	velocity = cocos2d::Vec2(BASE_SPEED, BASE_SPEED);

	lookDirection = Direction::left;
	moveDirection = Direction::left;
}


MovingObject::~MovingObject()
{
	//delete pointers
	sprite->removeFromParent();
}

//mutators
void MovingObject::setVelocity(const cocos2d::Vec2 newVelocity)
{
	velocity = newVelocity;
}

void MovingObject::setLookDirection(const Direction newDirection)
{
	lookDirection = newDirection;
}

void MovingObject::setMoveDirection(const Direction newDirection)
{
	moveDirection = newDirection;
}
//end of mutators

//accessors
cocos2d::Vec2 MovingObject::getVelocity() const
{
	return velocity;
}

cocos2d::Sprite * MovingObject::getSprite() const
{
	return sprite;
}

cocos2d::Vec2 MovingObject::getMiddlePosition() const
{
	return cocos2d::Vec2();
}

float MovingObject::getLeftSidePosition() const
{
	return sprite->getPositionX() - (width / 2);
}

float MovingObject::getRightSidePosition() const
{
	return sprite->getPositionX() + (width / 2);
}

float MovingObject::getTopPosition() const
{
	return sprite->getPositionY() + (height / 2);
}

float MovingObject::getBottomPosition() const
{
	return sprite->getPositionY() - (height / 2);
}

MovingObject::Direction MovingObject::getLookDirection() const
{
	return lookDirection;
}

MovingObject::Direction MovingObject::getMoveDirection() const
{
	return moveDirection;
}

float MovingObject::getWidth() const
{
	return width;
}

float MovingObject::getHeight() const
{
	return height;
}
//end of accessors

void MovingObject::updatePhysics(const float dt)
{
	//determine velocity based on movement direction
	switch (moveDirection)
	{
	case (up):
		velocity.x *= 0;
		if (velocity.y < 0)
			velocity.y *= -1;
		break;

	case (down):
		velocity.x *= 0;
		if (velocity.y > 0)
			velocity.y *= -1;
		break;

	case (left):
		velocity.y *= 0;
		if (velocity.x > 0)
			velocity.x *= -1;
		break;

	case (right):
		velocity.y *= 0;
		if (velocity.x < 0)
			velocity.x *= -1;
		break;
	}

	sprite->setPosition(sprite->getPosition() + velocity * dt); //update position
}
