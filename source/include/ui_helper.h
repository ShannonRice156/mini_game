#include "SDL.h"
#define SK_GL
#define NOMINMAX
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define GR_GL_CHECK_ERROR 0
#define GR_GL_LOG_CALLS 0

#include "skia/include/core/SkSurface.h"
#include "skia/include/core/SkPaint.h"
#include "skia/include/core/SkPath.h"

#include <skia/include/gpu/GrDirectContext.h>
#include <skia/include/gpu/gl/GrGLTypes.h>
#include <skia/include/core/SkImageInfo.h>

#include <include/core/SkCanvas.h>
#include <include/gpu/gl/GrGLInterface.h>
#include <include/gpu/GrDirectContext.h>

#include "src/gpu/gl/GrGLUtil.h"

#ifdef _WIN32
#include <Windows.h>
#include <gl/GL.h>
#endif



class ui_helper
{
public:
	ui_helper();
	ui_helper(int width, int height, SDL_Window* win);
	void init();
	void draw_square(float x, float y, float width, float height);
	void draw_circle(float centre_x, float centre_y, float radius);
	void render();
	void draw_image(std::string path, float x, float y);

private:
	sk_sp<SkSurface> sk_surface_;
	int width;
	int height;
	SDL_Window* win;
	SkCanvas* canvas_;
	SkPaint paint_;
	SDL_Event event;
	bool running = true;
	
};