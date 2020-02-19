#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Dice.h"
#include "DiceOne.h"
#include "DiceTwo.h"
#include "RollButton.h"
#include "Label.h"
#include "RandomImage.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	void rolldice();
	

	// getters
	glm::vec2 getMousePosition();
	void initializeLabels();
	void changeDiceOne(int dice);
	void changeDiceTwo(int dice);
	int DiceCombo();

private:
	std::string m_DiceOne, m_DiceTwo, m_DiceTotal, m_DiceOneLabel= "DiceOne1", m_DiceTwoLabel= "DiceTwo1";
	/*std::string m_DiceTwo;
	std::string m_DiceTotal;	
	std::string m_DiceOneLabel = "DiceOne1";
	std::string m_DiceTwoLabel =  "DiceTwo1";*/
	
	
	RollButton* m_pRollButton;
	DiceOne* m_pDiceOne;
	DiceTwo* m_pDiceTwo;
	RandomImage* m_pRandomImage[2];


	glm::vec2 m_mousePosition;
	Label* m_pDiceOneLbl;
	Label* m_pDiceTwoLbl;
	Label* m_pDiceResultLbl;

};

#endif /* defined (__LEVEL_1_SCENE__) */
