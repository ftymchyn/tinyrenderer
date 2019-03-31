NAME        = tinyrenderer
CC          = clang
CFLAGS      = -Wall -Wextra -Werror -O3

SRCS_DIR    = ./srcs
OBJS_DIR    = ./objs
HEADERS_DIR = ./includes

HEADERS     = tinyrenderer.h typedefs.h
HEADERS    := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

SRCS        = main.c init_sdl.c program_loop.c clear_sdl.c

OBJS        = $(SRCS:.c=.o)

ifneq ($(shell uname), Linux)
INCLUDES    = -I ./includes
INCLUDES   += -I /Library/Frameworks/SDL2.framework/Headers
LIBRARIES   = -L. /Library/Frameworks/SDL2.framework/SDL2
else
INCLUDES    = -I ./includes
INCLUDES   += -I /usr/include/SDL2/
LIBRARIES   = -lSDL2
endif

TO_LINKING  = $(addprefix $(OBJS_DIR)/, $(OBJS)) $(INCLUDES) $(LIBRARIES)

VPATH       = $(SRCS_DIR) $(OBJS_DIR) $(SRCS_DIR)/sdl_window


all         : $(NAME)

$(NAME)     : $(OBJS_DIR) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(TO_LINKING)
	@printf "\n\e[38;5;46m%-40s SUCCESSFUL BUILD 🖥\e[0m\n" ./$(NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ $(INCLUDES)
	@printf "%-40s \e[38;5;49mcompiled\e[0m\n" $<

clean       :
	rm -rf $(OBJS_DIR)

fclean      : clean
	rm -f $(NAME)

re          : fclean all
