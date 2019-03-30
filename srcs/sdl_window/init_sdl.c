#include "tinyrenderer.h"

static void	init_window(t_sdl *sdl)
{
	sdl->window = SDL_CreateWindow(
		PROGRAM_NAME,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		sdl->width,
		sdl->height,
		0);
	assert(sdl->window);
}

static void	init_renderer(t_sdl *sdl)
{
	sdl->renderer = SDL_CreateRenderer(
		sdl->window,
		-1,
		SDL_RENDERER_ACCELERATED);
	assert(sdl->renderer);
}

static void	init_canvas(t_sdl *sdl)
{
	sdl->canvas = SDL_CreateTexture(
		sdl->renderer,
		SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_TARGET,
		sdl->width,
		sdl->height);
	assert(sdl->canvas);
}

void		init_sdl(t_sdl *sdl, int width, int height)
{
	int init_result = SDL_Init(SDL_INIT_VIDEO);
	assert( init_result == 0 );
	
	sdl->width = width;
	sdl->height = height;

	init_window(sdl);
	init_renderer(sdl);
	init_canvas(sdl);
	
	sdl->pixels = (int*)malloc(sizeof(int) * (sdl->width * sdl->height));
	assert(sdl->pixels);
	bzero(sdl->pixels, sizeof(int) * ((sdl->width * sdl->height)));
}
