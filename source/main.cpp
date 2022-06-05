#include <window.h>
#include <iostream>

int main(int argc, char* argv[])
{
	int width = 1600;
	int height = 900;
	window win("space", width, height);

	win.init();

	while (win.running)
	{	
		win.poll();
	}

	return 0;
}