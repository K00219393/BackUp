#include "pch.h"
#include "Enemy.h"

void Enemy::spawn(Vector2f startPosition, float gravity)
{
	// Enemy Start Location
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Add Sprite
	m_Sprite.setPosition(m_Position);

}

void Enemy::update(float elapsedTime)
{


	// Update Rect for body
	FloatRect r = getPosition();


	// Move the sprite 
	m_Sprite.setPosition(m_Position);

}

FloatRect Enemy::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Enemy::getCenter()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2
	);
}

FloatRect Enemy::getBody()
{
	return m_Body;
}



Sprite Enemy::getSprite()
{
	return m_Sprite;
}


