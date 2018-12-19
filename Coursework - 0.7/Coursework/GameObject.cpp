#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;

	

	
}

void GameObject::Update()
{
	
	xpos=320;
	ypos=440;

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

	

	
}

void GameObject::pollEvents()
{
	SDL_Event event;
	
	//while (game->running()) 
		if (SDL_PollEvent(&event))
		{

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					xpos -= 100;
					break;
				}
			}

		}

	
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}