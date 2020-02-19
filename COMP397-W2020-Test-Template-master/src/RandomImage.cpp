#include "Randomimage.h"
#include "Game.h"
#include <ctime>


RandomImage::RandomImage()
{
	
	srand((int)(time(NULL)));
	
	m_dicePos = (1 + rand() % 6);

}

RandomImage::~RandomImage()
{
}

void RandomImage::draw()
{
}

void RandomImage::update()
{
}

void RandomImage::clean()
{
}

void RandomImage::spin()
{
	
	int spins = (10 + rand() % 50);

	for (int i = 1; i < spins; i++) {

		m_dicePos++;
		if (m_dicePos > 6)
		{
			m_dicePos = 1;
		}
	}
}

int RandomImage::getDicePos()
{
	return m_dicePos;
}