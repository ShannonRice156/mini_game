#include <iostream>
#include "SDL.h"
#include <ui_helper.h>

class window
{
public:
	SDL_Window* win{ nullptr };

	void render();
	window(std::string name, int width, int height);
	void init();

private:
	std::string name;
	int width;
	int height;
	int flags;
	bool closed;

	SDL_GLContext context{ nullptr };
	ui_helper ui;
	
};