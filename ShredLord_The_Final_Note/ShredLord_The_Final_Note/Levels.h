#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Levels
{
public:
	Vector2i m_LevelSize;
	Vector2f m_StartLocation;
	Vector2f m_PickUpStartLocation;
	float m_TimeModifer = 1;
	float m_TimeLimit = 0;
	int m_CurrentLevel = 0;
	const int NUM_LEVELS = 3;

public:
	const int Tile_Size = 50;
	const int Verts_IN_Quad = 4;

	float getTimeLimit();

	Vector2f getStartLocation();

	Vector2f getPickUpStartLocation();

	int** nextLevel(VertexArray& rVaLevel);

	Vector2i getLevelSize();

	int getCurrentLevel();

};
