#include "pch.h"
#include "PickUps.h"
#include "GameTexture.h"


PickUps::PickUps()
{
	m_Sprite = Sprite(GameTexture::GetTexture(
		"Graphics/MusicalSheet.png"));

	// How much is pickup worth
	m_Value = SHEET_START_VALUE;
}

void PickUps::spawn(Vector2f startPosition)
{
	// Place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);
}

FloatRect PickUps::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite PickUps::getSprite()
{
	return m_Sprite;
}

bool PickUps::isSpawned()
{
	return m_Spawned;
}

int PickUps::gotIt()
{
	m_Spawned = false;
	m_SecondsSinceDeSpawn = 0;
	return m_Value;
}

void PickUps::update(float elapsedTime)
{
	if (m_Spawned)
	{
		m_SecondsSinceSpawn += elapsedTime;
	}
	else
	{
		m_SecondsSinceDeSpawn += elapsedTime;
	}
}


