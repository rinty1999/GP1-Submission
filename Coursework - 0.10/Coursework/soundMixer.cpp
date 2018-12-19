#pragma once

#include <SDL_mixer.h>
#include "Game.h"
#include "soundMixer.h"


void playSounds() {



	//Mix_Music *themeMusic = Mix_LoadMUS("Game_Assets/music1.wav");
	//Mix_Chunk *sfx = Mix_LoadWAV("Game_Assets/eating_sound.wav");





	Mix_FreeMusic(themeMusic);
	Mix_FreeChunk(sfx);

	themeMusic = nullptr;
	sfx = nullptr;


	Mix_Quit();
}
