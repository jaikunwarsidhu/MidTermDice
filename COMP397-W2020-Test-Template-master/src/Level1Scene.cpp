#include "Level1Scene.h"
#include "Game.h"
#include "EndScene.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include<sstream>
#include <string>
#include <iostream>

Level1Scene::Level1Scene()
{
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pDiceOne->draw(m_DiceOneLabel);
	m_pDiceTwo->draw(m_DiceTwoLabel);
	m_pRollButton->draw();
	m_pDiceOneLbl->draw();
	m_pDiceTwoLbl->draw();
	m_pDiceResultLbl->draw();
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick();
	if (m_pRollButton->ButtonClick())
	{

		rolldice();
	}

}

void Level1Scene::clean()
{
	delete m_pRollButton;
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
				m_pRollButton->setClickOnce(0);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pRandomImage[0] = new RandomImage();
	m_pRandomImage[1] = new RandomImage();

	m_pRollButton = new RollButton();
	m_pRollButton->setMouseButtonClicked(false);
	addChild(m_pRollButton);

	initializeLabels();
	m_pDiceOne = new DiceOne();
	addChild(m_pDiceOne);
	m_pDiceTwo = new DiceTwo();
	addChild(m_pDiceTwo);
}

void Level1Scene::rolldice()
{
	m_pRandomImage[0]->spin();
	m_pRandomImage[1]->spin();

	int FirstDiceNum = m_pRandomImage[0]->getDicePos();
	int SecondDiceNum = m_pRandomImage[1]->getDicePos();

	std::stringstream oneStream;
	oneStream << FirstDiceNum;
	oneStream >> m_DiceOneLabel;
	std::stringstream twoStream;
	twoStream << SecondDiceNum;
	twoStream >> m_DiceTwoLabel;


	m_pDiceOneLbl->setText(m_DiceOneLabel);
	m_pDiceTwoLbl->setText(m_DiceTwoLabel);

	changeDiceOne(FirstDiceNum);
	changeDiceTwo(SecondDiceNum);



	int ResultDiceNum = FirstDiceNum + SecondDiceNum;
	std::stringstream resultStream;
	resultStream << ResultDiceNum;
	resultStream >> m_DiceTotal;
	m_pDiceResultLbl->setText("Result: " + m_DiceTotal);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::initializeLabels()
{
	SDL_Color black = { 0, 0, 0, 0.0 };
	SDL_Color red = { 255, 00, 00, 255 };


	//Adding labels
	m_pDiceOneLbl = new Label("One" + m_DiceOneLabel, "Dock51", 20, black, glm::vec2(210.0f, 265.0f));
	m_pDiceOneLbl->setParent(this);
	addChild(m_pDiceOneLbl);

	m_pDiceTwoLbl = new Label("Two" + m_DiceTwoLabel, "Dock51", 20, black, glm::vec2(450.0f, 265.0f));
	m_pDiceTwoLbl->setParent(this);
	addChild(m_pDiceTwoLbl);

	m_pDiceResultLbl = new Label("Total: " + m_DiceTotal, "Dock51", 30, red, glm::vec2(320.0f, 350.0f));
	m_pDiceResultLbl->setParent(this);
	addChild(m_pDiceResultLbl);
}

void Level1Scene::changeDiceOne(int dice)
{
	switch (dice)
	{
	case 1:
		m_DiceOneLabel = "DiceOne1";
		break;
	case 2:
		m_DiceOneLabel = "DiceOne2";
		break;
	case 3:
		m_DiceOneLabel = "DiceOne3";
		break;
	case 4:
		m_DiceOneLabel = "DiceOne4";
		break;
	case 5:
		m_DiceOneLabel = "DiceOne5";
		break;
	case 6:
		m_DiceOneLabel = "DiceOne6";
		break;
	}
}

void Level1Scene::changeDiceTwo(int dice)
{
	switch (dice)
	{
	case 1:
		m_DiceTwoLabel = "DiceTwo1";
		break;
	case 2:
		m_DiceTwoLabel = "DiceTwo2";
		break;
	case 3:
		m_DiceTwoLabel = "DiceTwo3";
		break;
	case 4:
		m_DiceTwoLabel = "DiceTwo4";
		break;
	case 5:
		m_DiceTwoLabel = "DiceTwo5";
		break;
	case 6:
		m_DiceTwoLabel = "DiceTwo6";
		break;
	}
}

int Level1Scene::DiceCombo()
{
	return 0;
}

