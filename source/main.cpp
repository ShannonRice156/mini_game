
#include <window.h>
#include <iostream>

int main(int argc, char* argv[])
{
	int width = 1600;
	int height = 900;
	window win("space", width, height);

	win.init();

	while (true)
	{	
		win.render();
	}

	SDL_DestroyWindow(win.win);
	SDL_Quit();

	return 0;
}