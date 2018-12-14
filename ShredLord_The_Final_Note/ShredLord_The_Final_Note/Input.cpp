#include "pch.h"
#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			// Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Play = true;
			}

			// Switch between full and split-screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}

		}
	}


	// Handle input specific to Shreddy Shuerger
	if (m_Shreddy.handleInput())
	{
		// Play a jump sound
		//m_SM.playJump();
	}
}


