#ifndef TINYRENDERER_H
# define TINYRENDERER_H

# include <assert.h>
# include "SDL.h"
# include "typedefs.h"

# define PROGRAM_NAME "tinyrenderer" 

void	init_sdl(t_sdl *sdl, int width, int height);
void	program_loop(t_sdl *sdl);
void	draw_frame(t_sdl *sdl);
void	clear_sdl(t_sdl *sdl);

#endif
