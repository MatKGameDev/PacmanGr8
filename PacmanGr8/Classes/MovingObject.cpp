#include "MovingObject.h"
#include "TileBase.h"

const cocos2d::Vec2 MovingObject::BASE_VELOCITY = cocos2d::Vec2(100, 100);

MovingObject::MovingObject(cocos2d::Vec2 position, std::string spriteFilePath)
{
	//create sprite and set initial values
	sprite = cocos2d::Sprite::create(spriteFilePath);
	sprite->setPosition(cocos2d::Vec2(position.x, position.y));
	width = sprite->getBoundingBox().size.width;
	height = sprite->getBoundingBox().size.height;

	velocity = BASE_VELOCITY;

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

cocos2d::Vec2 MovingObject::getCenterPosition() const
{
	return sprite->getPosition();
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
	//use look direction to determine if the object can change direction
	switch (lookDirection)
	{
		TileBase* tileToCheck;

	case (up): //check the tile above
		tileToCheck = TileBase::getTileAt(this->getCenterPosition() + cocos2d::Vec2(0, 30));
		if (tileToCheck->getType() != TileBase::Type::wall && tileToCheck->getType() != TileBase::Type::wall)
		{
			sprite->setPositionX(tileToCheck->getCenterPosition().x);
			moveDirection = lookDirection;
		}
		break;

	case (down): //check the tile below
		tileToCheck = TileBase::getTileAt(this->getCenterPosition() + cocos2d::Vec2(0, -30));
		if (tileToCheck->getType() != TileBase::Type::wall && tileToCheck->getType() != TileBase::Type::wall)
		{
			sprite->setPositionX(tileToCheck->getCenterPosition().x);
			moveDirection = lookDirection;
		}
		break;

	case (left): //check the tile to the left
		tileToCheck = TileBase::getTileAt(this->getCenterPosition() + cocos2d::Vec2(-30, 0));
		if (tileToCheck->getType() != TileBase::Type::wall && tileToCheck->getType() != TileBase::Type::wall)
		{
			sprite->setPositionY(tileToCheck->getCenterPosition().y);
			moveDirection = lookDirection;
		}
		break;

	case (right): //check the tile to the right
		tileToCheck = TileBase::getTileAt(this->getCenterPosition() + cocos2d::Vec2(30, 0));
		if (tileToCheck->getType() != TileBase::Type::wall && tileToCheck->getType() != TileBase::Type::wall)
		{
			sprite->setPositionY(tileToCheck->getCenterPosition().y);
			moveDirection = lookDirection;
		}
		break;
	}

	//determine velocity based on movement direction
	switch (moveDirection)
	{
	case (up):
		velocity.x = 0;
		velocity.y = BASE_VELOCITY.y;
		break;

	case (down):
		velocity.x = 0;
		velocity.y = -BASE_VELOCITY.y;
		break;

	case (left):
		velocity.x = -BASE_VELOCITY.x;
		velocity.y = 0;
		break;

	case (right):
		velocity.x = BASE_VELOCITY.x;
		velocity.y = 0;
		break;
	}

	sprite->setPosition(sprite->getPosition() + velocity * dt); //update position

	//check for map bounds (teleport player to other side)
	if (getCenterPosition().x < 300)
		sprite->setPositionX(1140);
	else if (getCenterPosition().x > 1140)
		sprite->setPositionX(300);
}
