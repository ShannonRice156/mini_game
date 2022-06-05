#pragma once
#include <iostream>
#include "SDL.h"
#include <ui_helper.h>
#include <stage.h>

class window
{
public:
	SDL_Window* win{ nullptr };

	void render();
	window(std::string name, int width, int height);
	void init();
	bool running = true;
	void poll();

	void handle_keydown();
	void handle_keyup();
	void handle_mousedown();
	void handle_mouseup();

private:
	std::string name;
	int width;
	int height;
	int flags;
	bool closed;

	SDL_GLContext context{ nullptr };
	ui_helper ui;
	SDL_Event event;
	stage win_stage;
	
};