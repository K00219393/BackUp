#include "pch.h"
#include "Engine.h"

void Engine::loadLevels()
{
	m_Play = false;

	//Deletes the allocated memory that was used last
	for (int i = 0; i < m_L.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];

	}
	delete[] m_ArrayLevel;

	//loads the 2d array map for the level, while repopulate the vertex array as well
	m_ArrayLevel = m_L.nextLevel(m_VALevel);

	//preparing the sound emitters
	//populateEmitters(m_FireEmitters, m_ArrayLevel);

	// How long is this new time limit
	 m_TimeRemaining = m_L.getTimeLimit(); 

	// Spawn Player
	 m_Shreddy.spawn(m_L.getStartLocation(), GRAVITY);

	 // Spawn PickUp
	 m_MusicSheet.spawn(m_L.getPickUpStartLocation());
	

	// Make sure this code isn't run again
	m_NewLevelRequired = false;

}