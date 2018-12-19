#include "Map.h"
#include "TextureManager.h"

Map::Map()
{
	dirt = TextureManager::LoadTexture("Game_Assets/dirt.png");
	grass = TextureManager::LoadTexture("Game_Assets/grass.png");
	water = TextureManager::LoadTexture("Game_Assets/water.png");
}

void Map::LoadMap()
{}

void Map::DrawMap()
{}