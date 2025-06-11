CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

MANDATORY =  ft_print_base.c ft_print_unsigned.c ft_print_char.c  ft_print_hexaMaj.c  ft_print_hexMin.c  ft_print_str.c  ft_printf.c  ft_print_pointer.c
SRCS = $(MANDATORY)

OBJ = $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re