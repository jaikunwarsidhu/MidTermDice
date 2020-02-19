#pragma once
#ifndef __DICE_ONE__
#define __DICE_ONE__


#include "DisplayObject.h"

class DiceOne : public DisplayObject
{
public:
	DiceOne();
	~DiceOne();

	void draw() override;
	void update() override;
	void clean() override;
	void draw(std::string imageID);
};
#endif