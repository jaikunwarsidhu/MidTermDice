#include "DiceTwo.h"
#include "Game.h"

DiceTwo::DiceTwo()
{
	//Loading all textures
	TheTextureManager::Instance()->load("../Assets/textures/1.png",
		"DiceTwo1", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/2.png",
		"DiceTwo2", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/3.png",
		"DiceTwo3", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/4.png",
		"DiceTwo4", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/5.png",
		"DiceTwo5", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/6.png",
		"DiceTwo6", TheGame::Instance()->getRenderer());


	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("DiceTwo1");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(425, 140));
	setType(DICE_TWO);
}

DiceTwo::~DiceTwo()
{
}

void DiceTwo::draw()
{
}

void DiceTwo::update()
{
}

void DiceTwo::clean()
{
}

void DiceTwo::draw(std::string imageID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(imageID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}
