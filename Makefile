#FdF_PROJECT_MAKEFILE
include lib/libft/.make
NAME			:= fdf

READER_NAME		:= reader.c open_close_file.c read_file.c create_list.c convert_lines_to_int_arrays.c \
					convert_lines_to_strings_arrays.c clear_tlist_mixed.c free_2d_array.c check_arrays_len.c \
					strings_arrays_to_int_color_arrays.c list_to_map.c list_to_int_arrays.c do_nothing.c \
					color.c find_min_max_2d_array.c 
READER_PATH		:= ./srcs/reader/
READER			:= $(addprefix $(READER_PATH), $(READER_NAME))

DRAWER_NAME		:= drawer.c tp_initialise.c track_keys.c track_scroll.c draw_img.c put_img.c calculate_rotation_matrix.c put_lines.c get_screen_coordinates.c rotate_coordinates.c
DRAWER_PATH		:= ./srcs/drawer/
DRAWER			:= $(addprefix $(DRAWER_PATH), $(DRAWER_NAME))

SRCS_NAME		:=	main.c 
SRCS_PATH		:=	./srcs/
SRCS			:=	$(addprefix $(SRCS_PATH), $(SRCS_NAME)) $(READER) $(DRAWER)

LIBFT_PATH		:=	lib/$(LIBFT_PATH)
LIBFT			:=	$(addprefix $(LIBFT_PATH), $(LIBFT))
LIBFT_SOURSES	:=	$(addprefix $(LIBFT_PATH), $(LIBFT_SOURSES))

LIBMLX			:= ./lib/MLX42
HEADERS			:=	-I $(LIBMLX)/include -I ./ 
MLX				:=	./lib/MLX42/build/libmlx42.a
LIBS			:=	-L$(LIBMLX)/build -lmlx42 -L$(LIBFT_PATH) -lft -L"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -framework Cocoa -framework OpenGL -framework IOKit
# LIBS			:=	-L$(LIBMLX)/build -lmlx42 -L$(LIBFT_PATH) -lft -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib/" -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -lm -c $< -o $@ $(HEADERS) 

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	@cc $(FLAGS) -lm $(SRCS) $(LIBFT) $(HEADERS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)\n------------->FdF created successfully!<------------$(EC)"

$(LIBFT): $(LIBFT_SOURSES)
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(NAME).dSYM
	@rm -rf .DS_Store
	@echo "$(GREEN)*.o files removed!$(EC)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)All files removed!$(EC)"

re: fclean all