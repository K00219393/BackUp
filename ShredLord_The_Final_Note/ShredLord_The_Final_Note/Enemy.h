#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
protected:
	// Sprite for enemy
	Sprite m_Sprite;

	// Private variables and functions come next
private:

	// Enemy Speed
	float m_Speed = 400;

	// Enemy Location
	Vector2f m_Position;

	// Enemy Body
	FloatRect m_Body;


	// Texture
	Texture m_Texture;

	// Public Functions
public:

	void spawn(Vector2f startPosition, float gravity);

	// Where is the Enemy
	FloatRect getPosition();

	// rextangle for Sprite
	FloatRect getBody();

	// Send Sprite to main
	Sprite getSprite();

	// Enemy Center
	Vector2f getCenter();

	// Update Function
	void update(float elapsedTime);
};