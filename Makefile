NAME = fdf

SRCS_F = main.c reader.c open_close_file.c read_file.c create_list.c convert_lines_to_int_arrays.c \
	   convert_lines_to_strings_arrays.c clear_tlist_mixed.c free_2d_array.c check_arrays_len.c \
	   strings_arrays_to_int_color_arrays.c list_to_map.c list_to_int_arrays.c do_nothing.c 

SRCS_P = ./srcs/

LIBFT = libft/libft.a

SRCS = $(addprefix $(SRCS_P), $(SRCS_F)) 

GREEN = \033[0;32m
NC = \033[0m

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)



$(NAME): $(SRCS) $(LIBFT)
	@cc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)fdf created successfully!$(NC)"

$(LIBFT): 
	@$(MAKE) -C libft/

clean:
	@$(MAKE) clean -C libft/
	@echo "$(GREEN)Helper files removed!$(NC)"


fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft/
	@echo "$(GREEN)fdf removed!$(NC)"




re: fclean all

