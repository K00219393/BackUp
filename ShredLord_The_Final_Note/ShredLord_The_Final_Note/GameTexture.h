#pragma once

#ifndef GAMETEXTURE_H
#define GAMETEXTURE_H

#include <SFML/Graphics.hpp>

#include <map>

class GameTexture
{
private:
	std::map<std::string, sf::Texture>m_Textures;

	static GameTexture* Instance;

public:
	GameTexture();
	static sf::Texture& GetTexture(std::string const& filename);

};
#endif
