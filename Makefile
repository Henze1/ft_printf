CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC = ft_printaddr.c \
	ft_printchar.c \
	ft_printf.c \
	ft_printstring.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)
	@$(CC) $(CFLAGS) $(SRC) -o start
	@./start
	@rm -r start

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
