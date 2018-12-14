#include "Levels.h"
#include "pch.h"
#include "GameTexture.h"
#include "Engine.h"
#include <sstream>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int** Levels::nextLevel(VertexArray& rVaLevel)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	m_CurrentLevel++;
	if (m_CurrentLevel > NUM_LEVELS)
	{
		m_CurrentLevel = 1;
		m_TimeModifer -= .1f;
	}

	string leveltoload;
	switch (m_CurrentLevel)
	{
	case 1:
		leveltoload = "levels/level1.txt";
		m_StartLocation.x = 70;
		m_StartLocation.y = 750;

		m_PickUpStartLocation.x = 950;
		m_PickUpStartLocation.y = 250;

		m_TimeLimit = 300.0f;
		break;

	}

	ifstream inputFile(leveltoload);
	string s;


	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}

	m_LevelSize.x = s.length();

	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int** arrayLevel = new int*[m_LevelSize.y];

	for (int i = 0; i < m_LevelSize.y; i++)
	{
		arrayLevel[i] = new int[m_LevelSize.x];

	}

	string row;
	int y = 0;

	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);

		}
		y++;

	}

	inputFile.close();

	rVaLevel.setPrimitiveType(Quads);

	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * Verts_IN_Quad);

	int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; x++)
	{
		for (int y = 0; y < m_LevelSize.y; y++)
		{
			// Position each vertex in the current quad
			rVaLevel[currentVertex + 0].position =
				Vector2f(x * Tile_Size, y * Tile_Size);

			rVaLevel[currentVertex + 1].position =
				Vector2f((x * Tile_Size) + Tile_Size, y * Tile_Size);

			rVaLevel[currentVertex + 2].position =
				Vector2f((x * Tile_Size) + Tile_Size, (y * Tile_Size) + Tile_Size);

			rVaLevel[currentVertex + 3].position =
				Vector2f((x * Tile_Size), (y * Tile_Size) + Tile_Size);

			// Which tile from the sprite sheet should we use
			int verticalOffset = arrayLevel[y][x] * Tile_Size;

			Vector2f(0, 0 + verticalOffset);

			rVaLevel[currentVertex + 0].texCoords =
				Vector2f(0, 0 + verticalOffset);

			rVaLevel[currentVertex + 1].texCoords =
				Vector2f(Tile_Size, 0 + verticalOffset);

			rVaLevel[currentVertex + 2].texCoords =
				Vector2f(Tile_Size, Tile_Size + verticalOffset);

			rVaLevel[currentVertex + 3].texCoords =
				Vector2f(0, Tile_Size + verticalOffset);

			// Position ready for the next four vertices
			currentVertex = currentVertex + Verts_IN_Quad;
		}
	}
	return arrayLevel;
}

Vector2i Levels::getLevelSize()
{
	return m_LevelSize;
}

int Levels::getCurrentLevel()
{
	return m_CurrentLevel;
}

float Levels::getTimeLimit()
{
	return m_TimeLimit * m_TimeModifer;
}

Vector2f Levels::getStartLocation()
{
	return m_StartLocation;
}

Vector2f Levels::getPickUpStartLocation()
{
	return m_PickUpStartLocation;
}