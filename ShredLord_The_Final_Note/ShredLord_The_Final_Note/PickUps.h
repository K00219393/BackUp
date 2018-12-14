#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PickUps
{
public:
	const int SHEET_START_VALUE = 15;
	const int START_WAIT_TIME = 10;
	const int START_SECONDS_TO_LIVE = 100;

	// The sprite that represents this pickup
	Sprite m_Sprite;

	// Where is the pick up
	Vector2f m_Position;

	// How much is this pickup worth?
	int m_Value;

	// What type of pickup is this? 
	int m_Type;

	// Handle spawning and disappearing
	bool m_Spawned;
	float m_SecondsSinceSpawn;
	float m_SecondsSinceDeSpawn;
	float m_SecondsToLive;
	float m_SecondsToWait;

public:
	PickUps();

	void spawn(Vector2f startPosition);

	// Check the position of a pickup
	FloatRect getPosition();

	// Get the sprite for drawing
	Sprite getSprite();

	// Let the pickup update itself each frame
	void update(float elapsedTime);

	// Is this pickup currently spawned?
	bool isSpawned();

	// Get the goodness from the pickup
	int gotIt();

	// Upgrade the value of each pickup
	//void upgrade();

};

