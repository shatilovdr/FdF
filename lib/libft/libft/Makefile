#LIBFT_PROJECT_MAKEFILE
include ../.make
NAME	:=	libft.a
OBJ	:=	$(LFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJ)
	@ar -crs ../libft.a $(OBJ)
	@echo "$(GREY)-LIBFT_PRJ is ready$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BNS)
	@rm -rf .bonus
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

print:
	@echo $(LIBFT_SRCS)