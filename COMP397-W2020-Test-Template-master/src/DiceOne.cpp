#include "DiceOne.h"
#include "Game.h"

DiceOne::DiceOne()
{
	//Loading all textures
	TheTextureManager::Instance()->load("../Assets/textures/1.png",
		"DiceOne1", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/2.png",
		"DiceOne2", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/3.png",
		"DiceOne3", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/4.png",
		"DiceOne4", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/5.png",
		"DiceOne5", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/6.png",
		"DiceOne6", TheGame::Instance()->getRenderer());
	

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("DiceOne1");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(200, 150));
	setType(DICE_ONE);
}

DiceOne::~DiceOne()
{
}

void DiceOne::draw()
{
}

void DiceOne::update()
{
}

void DiceOne::clean()
{
}

void DiceOne::draw(std::string imageID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

		TheTextureManager::Instance()->draw(imageID, xComponent, yComponent,
			TheGame::Instance()->getRenderer(), 0, 255, true);
}
