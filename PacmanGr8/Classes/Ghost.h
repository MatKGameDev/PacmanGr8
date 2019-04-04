#pragma once
#include "MovingObject.h"

class Ghost : public MovingObject
{
public:
	Ghost(std::string spriteFilePath);
	~Ghost();
};

