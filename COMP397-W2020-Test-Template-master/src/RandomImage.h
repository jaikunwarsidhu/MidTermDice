#pragma once
#ifndef __RANDOM_IMAGE__
#define __RANDOM_IMAGE__

#include "GameObject.h"

class RandomImage : public GameObject
{

public:

	RandomImage();
	~RandomImage();

	void draw() override;
	void update() override;
	void clean() override;

	void spin();
	int getDicePos();



private:

	int m_dicePos;


};



#endif /*Defined __RANDOM_IMAGE__ */