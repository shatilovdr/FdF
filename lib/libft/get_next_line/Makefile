#GET_NEXT_LINE_PROJECT_MAKEFILE
include ../.make
NAME = get_next_line.a
OBJ = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@ar -crs $(NAME) $(OBJ)
	@ar -crs ../libft.a $(OBJ)
	@echo "$(GREY)-GET_NEXT_LINE_PRJ is ready$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BNS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re