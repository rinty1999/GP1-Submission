#include "Game.h"
#include "GameObject.h"
#include "main.h"

Game *game = nullptr;
//SDL_PollEvent event;

int main(int argc, char *argv[])
{

	const int FPS = 60;
	const int Delay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("GameWindow", 800, 640, false);
	
	while (game->running())
	{
		
		frameStart = SDL_GetTicks();
		
		game->handleEvents();
		game->update();
		game->render();
		

		/*if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_LEFT) 
				{
					xpos -= 100;
				}
			}

		}*/

		frameTime = SDL_GetTicks() - frameStart;

		if (Delay > frameTime)
		{
			SDL_Delay(Delay - frameTime);
		}

	}

	game->clean();
	return 0;
}