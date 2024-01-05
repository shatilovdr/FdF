#PRINTF_PROJECT_MAKEFILE
include ../.make
NAME	=	libftprintf.a
OBJ		=	$(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@ar -crs $(NAME) $(OBJ)
	@ar -crs ../libft.a $(OBJ)
	@echo "$(GREY)-PRINTF_PRJ is ready$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re