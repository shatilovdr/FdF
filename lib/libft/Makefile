#LIBFT_MAKEFILE
include .make
NAME = libft.a

all: $(NAME)

$(NAME): $(LIBFT_SOURSES)
	@echo	"$(GREEN)+--------------------------------------------------------+$(EC)"
	@echo	"$(GREEN)|                     BUILDING LIBFT                     |$(EC)"
	@echo	"$(GREEN)+--------------------------------------------------------+$(EC)"
	@$(MAKE) -C libft/
	@$(MAKE) -C printf/
	@$(MAKE) -C get_next_line/
	@echo	"$(GREEN)+--------------------------------------------------------+$(EC)"
	@echo	"$(GREEN)|                     LIBFT IS READY!                    |$(EC)"
	@echo	"$(GREEN)+--------------------------------------------------------+$(EC)"
clean:
	@$(MAKE) clean -C libft/
	@$(MAKE) clean -C printf/
	@$(MAKE) clean -C get_next_line/

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft/
	@$(MAKE) fclean -C printf/
	@$(MAKE) fclean -C get_next_line/

re: fclean all