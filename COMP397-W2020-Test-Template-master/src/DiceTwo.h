#pragma once
#pragma once
#ifndef __DICE_TWO__
#define __DICE_TWO__


#include "DisplayObject.h"

class DiceTwo : public DisplayObject
{
public:
	DiceTwo();
	~DiceTwo();

	void draw() override;
	void update() override;
	void clean() override;
	void draw(std::string imageID);
};
#endif