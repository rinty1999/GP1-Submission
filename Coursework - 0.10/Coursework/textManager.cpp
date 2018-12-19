#include "textManager.h"
#include <iostream>
#include "Game.h"

//void Text :: display() const {}

Text::Text(SDL_Renderer *renderer, const std::string &fontPath,
	int fontSize, const std::string &messageText, 
	const SDL_Color &color)
{
	textTexture = loadFont(renderer, fontPath, fontSize, messageText, color);
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
}

void Text::display(int x, int y, SDL_Renderer *renderer) const
{
	textRect.x = x;
	textRect.y = y;

	SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}

SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &fontPath,
	int fontSize, const std::string &messageText,
	const SDL_Color &color) {

	TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);

	auto textSurface = TTF_RenderText_Solid(font, messageText.c_str(), color);

	auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_FreeSurface(textSurface);
	return textTexture;
	
}


