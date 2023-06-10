#pragma once
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
#include <geometry.h>
#include <gl/GL.h>
#endif



class ui_helper
{
public:
	ui_helper();
	ui_helper(int width, int height, SDL_Window* win);
	void init();
	void draw_square(rect item_rect, SkPaint::Style fill, SkColor color);
	void draw_circle(vector pos, float radius, SkPaint::Style fill, SkColor color);
	void draw_background();
	void render();
	void draw_image(std::string path, float x, float y);
	SkCanvas* canvas_;

private:
	sk_sp<SkSurface> sk_surface_;
	int width;
	int height;
	SDL_Window* win;
	SkPaint paint_;
	void poll();
};