#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include <SDL_ttf.h>
#include "soundMixer.h"

GameObject* player;
//GameObject* food;
Map* map;
SDL_Texture* foodTexture1;
SDL_Texture* foodTexture2;
SDL_Texture* foodTexture3;
SDL_Rect srcR, destR;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;




Game::Game()
{
	destR.x = rand() % 640;
}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;	
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	while (isRunning)
	{
		if (!Mix_PlayingMusic())
		{
			Mix_PlayMusic(themeMusic, -1);
		}
	}

	player = new GameObject("Game_Assets/howl.png", 0, 0);
	//food = new GameObject("Game_Assets/mouse1.png", 0, 0);
	map = new Map();

	SDL_Surface* tmpSurface1 = IMG_Load("Game_Assets/mouse1.png");
	foodTexture1 = SDL_CreateTextureFromSurface(renderer, tmpSurface1);
	SDL_FreeSurface(tmpSurface1);

	SDL_Surface* tmpSurface2 = IMG_Load("Game_Assets/mouse1.png");
	foodTexture2 = SDL_CreateTextureFromSurface(renderer, tmpSurface2);
	SDL_FreeSurface(tmpSurface2);

	SDL_Surface* tmpSurface3 = IMG_Load("Game_Assets/mouse1.png");
	foodTexture3 = SDL_CreateTextureFromSurface(renderer, tmpSurface3);
	SDL_FreeSurface(tmpSurface3);
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	/*SDL_Event event;
	if (SDL_PollEvent(&event))
	{

		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_a:
				xpos -= 10;
				break;
			}
		}

	}*/
}

void Game::update()
{
	player->Update();
	//food->Update();
	destR.h = 32;
	destR.w = 32;
	destR.y = destR.y++;

}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	SDL_RenderCopy(renderer, foodTexture1, NULL, &destR);
	SDL_RenderCopy(renderer, foodTexture2, NULL, &destR);
	SDL_RenderCopy(renderer, foodTexture3, NULL, &destR);
	player->Render();
	//food->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}