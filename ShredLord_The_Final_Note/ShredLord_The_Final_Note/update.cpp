#include "pch.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// Load a level
		loadLevels();
	}

	if (m_Play)
	{
		// Update player character
		m_Shreddy.update(dtAsSeconds);

		

		// Detect collisions and see if characters have reached the goal tile
		// The second part of the if condition is only executed
		// when thomas is touching the home tile
		if (detectCollisions(m_Shreddy))
		{
			// New level required
			m_NewLevelRequired = true;

			/* Play the reach goal sound
			m_SM.playReachGoal(); */

		}
		else
		{
			// Run Shreddys collision detection
			detectCollisions(m_Shreddy);
		}

		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Have Shreddy run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	}// End if playing

	// Check if a fire sound needs to be played
	vector<Vector2f>::iterator it;

	/* Iterate through the vector of Vector2f objects
	for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++)
	{
		// Where is this emitter?
		// Store the location in pos
		float posX = (*it).x;
		float posY = (*it).y;

		// is the emiter near the player?
		// Make a 500 pixel rectangle around the emitter
		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		/* Is the player inside localRect?
		if (m_Thomas.getPosition().intersects(localRect))
		{
			// Play the sound and pass in the location as well
			m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());
		} 
	}*/

	// Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Shreddy.getCenter());
		
	} 
	else
	{
		// Centre full screen around appropriate character
		if (m_Player1)
		{
			m_MainView.setCenter(m_Shreddy.getCenter());
		}
		/*else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}*/
	} 

	// Time to update the HUD?
	// Increment the number of frames since the last HUD calculation
	m_FramesSinceLastHUDUpdate++;

	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{
		// Update game HUD text
		stringstream ssTime;
		stringstream ssLevel;

		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		// Update the level text
		ssLevel << "Level:" << m_L.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());

		m_FramesSinceLastHUDUpdate = 0;
	}

}// End of update function