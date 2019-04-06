#pragma once
#include "TileBase.h"

class FruitTile : public TileBase
{
public:
	enum FruitType
	{
		apple,
		orange
	};

	static const float LIFETIME;

	static std::vector<FruitTile*> fruitTileList;

	FruitTile(cocos2d::Vec2 a_position, cocos2d::Scene* sceneToAddTo, FruitType a_type);
	~FruitTile();

	int getScoreValue() const;
	float getLifeTimer() const;

	void setFruit(const FruitType a_type, cocos2d::Scene* sceneToAddTo);

	void reduceLifeTimer(const float amount);
	bool checkAndResolveExpiry();

	void resolveCollision() override;

private:
	cocos2d::Sprite* sprite;

	int scoreValue;
	float lifeTimer;

	FruitType type;
};

