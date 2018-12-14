#include "pch.h"
#include "ShreddyShuerger.h"
#include "GameTexture.h"

ShreddyShuerger::ShreddyShuerger()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(GameTexture::GetTexture(
		"Graphics/runRight0.png"));

	m_JumpDuration = .25;

	m_Sprite.setOrigin(1.05, 1.25);
}

bool ShreddyShuerger::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{

		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}

	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;

	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;

	}
	else
	{
		m_LeftPressed = false;
	}


	if (Keyboard::isKeyPressed(Keyboard::Right))
	{

		m_RightPressed = true;;

	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}