NAME        = tinyrenderer
CC          = clang
CFLAGS      = -Wall -Wextra -Werror -O3 -fsanitize=address

LIBFT_DIR   = ./libft
LIBFT_INCL  = $(LIBFT_DIR)/includes/
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS_DIR    = ./srcs
OBJS_DIR    = ./objs
HEADERS_DIR = ./includes

HEADERS     = common.h sdl_window.h render.h math.h utils.h object.h
HEADERS    := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

SRCS        = main.c get_sdl_context.c init_sdl.c program_loop.c clear_sdl.c
SRCS       += update_window.c set_pixel_color.c draw_line.c abs.c clamp.c swap.c
SRCS       += load_mesh.c clear_mesh.c render.c draw_face.c draw_triangle.c
SRCS       += cross.c clamp_screen_coord.c

OBJS        = $(SRCS:.c=.o)

ifneq ($(shell uname), Linux)
INCLUDES    = -I ./includes -I $(LIBFT_INCL)
INCLUDES   += -I /Library/Frameworks/SDL2.framework/Headers
LIBRARIES   = -L. /Library/Frameworks/SDL2.framework/SDL2
else
INCLUDES    = -I ./includes -I $(LIBFT_INCL)
INCLUDES   += -I /usr/include/SDL2/
LIBRARIES   = -lSDL2 -L. $(LIBFT)
endif

TO_LINKING  = $(addprefix $(OBJS_DIR)/, $(OBJS)) $(INCLUDES) $(LIBRARIES)

SRCS_SUBDIR = sdl_window render utils math object
VPATH       = $(SRCS_DIR) $(addprefix $(SRCS_DIR)/, $(SRCS_SUBDIR)) $(OBJS_DIR)


.PHONY: all clean fclean re


all         : $(NAME)

$(NAME)     : $(LIBFT) $(OBJS_DIR) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(TO_LINKING)
	@printf "\n\e[38;5;46m%-40s SUCCESSFUL BUILD 🖥\e[0m\n" ./$(NAME)

$(LIBFT)    :
	make -C $(LIBFT_DIR) -j 4

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS)     : %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ $(INCLUDES)
	@printf "%-40s \e[38;5;49mcompiled\e[0m\n" $<

clean       :
	rm -rf $(OBJS_DIR)

fclean      : clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re          : fclean all
