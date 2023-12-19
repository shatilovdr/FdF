NAME = fdf

SRCS_F = main.c reader.c open_close_file.c read_file.c create_list.c convert_lines_to_int_arrays.c \
	   convert_lines_to_strings_arrays.c clear_tlist_mixed.c free_2d_array.c check_arrays_len.c \
	   strings_arrays_to_int_color_arrays.c list_to_map.c list_to_int_arrays.c do_nothing.c \
	   color.c draw.c

SRCS_P = ./srcs/

LIBFT = libft/libft.a
LIBFT_DIR		:= ./libft/
LIBMLX			:= ./lib/MLX42

SRCS = $(addprefix $(SRCS_P), $(SRCS_F))
OBJS	:= $(SRCS:.c=.o)

GREEN = \033[0;32m
NC = \033[0m

FLAGS = -Wall -Wextra -Werror -g 
HEADERS	:= -I $(LIBMLX)/include -I ./ 
MLX		:= ./lib/MLX42/build/libmlx42.a
LIBS	:=  -L$(LIBMLX)/build -lmlx42 -L$(LIBFT_DIR) -lft -L"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -framework OpenGL -framework AppKit
all: $(NAME) libmlx

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) 

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	@cc $(FLAGS) $(SRCS) $(LIBFT) $(HEADERS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)fdf created successfully!$(NC)"

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT): 
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(GREEN)Helper files removed!$(NC)" 
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)fdf removed!$(NC)"




re: fclean all

