#include <ui_helper.h>

ui_helper::ui_helper()
{
}

ui_helper::ui_helper(int width, int height, SDL_Window* win) {
	this->width = width;
	this->height = height;
	this->win = win;
};

void ui_helper::init() {
	uint32_t window_format = SDL_GetWindowPixelFormat(win);
	SkColorType colour_type;

	if (window_format == SDL_PIXELFORMAT_RGBA8888)
	{
		colour_type = kRGBA_8888_SkColorType;
	}
	else
	{
		colour_type = kBGRA_8888_SkColorType;
	}

	sk_sp<const GrGLInterface> native_gl_interface = GrGLMakeNativeInterface();
	sk_sp<GrDirectContext> gr_context_ = GrDirectContext::MakeGL(native_gl_interface);

	GrGLint gl_buffer;
	GR_GL_GetIntegerv(native_gl_interface.get(), GR_GL_RENDERBUFFER_BINDING, &gl_buffer);

	GrGLFramebufferInfo buffer_info;
	buffer_info.fFBOID = gl_buffer;

	if (colour_type == kRGBA_8888_SkColorType)
	{
		buffer_info.fFormat = GR_GL_RGBA8;
	}
	else
	{
		buffer_info.fFormat = GR_GL_RGBA8;
	}

	GrBackendRenderTarget backend_target{
	static_cast<int>(width),
	static_cast<int>(height),
	1,
	8,
	buffer_info };

	sk_surface_ = SkSurface::MakeFromBackendRenderTarget(
		gr_context_.get(),
		backend_target,
		kTopLeft_GrSurfaceOrigin,
		colour_type,
		nullptr,
		nullptr);

	canvas_ = sk_surface_->getCanvas();
	paint_.setStrokeWidth(1);

	paint_.setAntiAlias(true);
};

void ui_helper::draw_image(std::string path, float x, float y) {
	SkString path_img = SkStringPrintf(path.c_str());
	sk_sp<SkImage> image = SkImage::MakeFromEncoded(SkData::MakeFromFileName(path_img.c_str()));

	canvas_->drawImage(image, x, y);
}

void ui_helper::draw_background() {
	paint_.setStyle(SkPaint::kFill_Style);
	paint_.setColor(SkColorSetRGB(136, 136, 136));

	SkPath path;
	path.moveTo(0, 0);
	path.lineTo(0, 0 + height);
	path.lineTo(0 + width, 0 + height);
	path.lineTo(0 + width, 0);
	path.lineTo(0, 0);
	
	canvas_->drawPath(path, paint_);
}

void ui_helper::draw_square(rect item_rect, SkPaint::Style fill, SkColor color) {
	paint_.setStyle(fill);
	paint_.setColor(color);

	SkPath path;
	path.moveTo(item_rect.minx, item_rect.miny);
	path.lineTo(item_rect.minx, item_rect.miny + item_rect.height);
	path.lineTo(item_rect.minx + item_rect.width, item_rect.miny + item_rect.height);
	path.lineTo(item_rect.minx + item_rect.width, item_rect.miny);
	path.lineTo(item_rect.minx, item_rect.miny);

	canvas_->drawPath(path, paint_);
}

void ui_helper::draw_circle(vector pos, float radius, SkPaint::Style fill, SkColor color) {
	paint_.setStyle(SkPaint::kStroke_Style);
	paint_.setColor({ 0, 0, 0, 1 });
	canvas_->drawCircle(pos.x, pos.y, radius, paint_);

}