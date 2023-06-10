#include <window.h>

window::window(std::string name, int width, int height) {
	this->name = name;
	this->width = width;
	this->height = height;
	
	closed = false;
	flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

	win = SDL_CreateWindow(
		name.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		flags);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "SDL INITIALISATION FAILED" << std::endl;
		std::cout << "Error message: " << SDL_GetError() << std::endl;
		return;
	}

	if (win == nullptr)
	{
		std::cout << "Failed creating window" << std::endl;
		std::cout << "Error message: " << SDL_GetError() << std::endl;
		return;
	}

	std::cout << "Window created" << std::endl;

	context = SDL_GL_CreateContext(win);

	if (context == nullptr)
	{
		std::cout << "Failed to create context" << std::endl;
		std::cout << "Error message: " << SDL_GetError() << std::endl;
		return;
	}

	std::cout << "Success" << std::endl;

	ui = ui_helper(width, height, win);

}

void window::render() {

	ui.canvas_->clear(SK_ColorWHITE);

	ui.draw_background();

	win_stage.render(ui);

	ui.canvas_->flush();
	SDL_GL_SwapWindow(win);

};


void window::init() {
	ui.init();
};

void window::poll() {
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			running = false;
			SDL_DestroyWindow(win);
			SDL_Quit();
		}
		else if (event.type == SDL_KEYDOWN) {
			// keydown
			handle_keydown();
		}
		else if (event.type == SDL_KEYUP) {
			// keydown
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN) {
			// mouse click
		}
		running = event.type != SDL_QUIT;

		render();
	}
}


void window::handle_keydown() {
	//stage.handle_keydown
	win_stage.handle_keydown(event.key.keysym.sym);

}

void window::handle_keyup()
{
}

void window::handle_mousedown()
{
}

void window::handle_mouseup()
{
}
