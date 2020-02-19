#include "RollButton.h"
#include "Game.h"

RollButton::RollButton()
	:Button(
		"../Assets/textures/rollButton.png",
		"spin",
		ROLL_BUTTON, glm::vec2(340, 410.0f)), m_isClicked(false)
	
{
	
}

RollButton::~RollButton()
{
}

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{			
			std::cout << "Roll Button Clicked!" << std::endl;

			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}

int RollButton::countsClickOnce()
{
	return m_pClickFlag;
}

void RollButton::setClickOnce(int clickCount)
{
	m_pClickFlag = clickCount;
}
