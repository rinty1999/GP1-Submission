#pragma once
#include <SDL.h>
#include "Game.h"
#include <SDL_mixer.h>




	Mix_Music *themeMusic = Mix_LoadMUS("Game_Assets/music1.wav");
	Mix_Chunk *sfx = Mix_LoadWAV("Game_Assets/eating_sound.wav");



void playSounds();
