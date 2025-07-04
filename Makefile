CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
LDFLAGS		= -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_DIR		= ./minilibx_linux --no-print-directory
GNL_SRC		= $(addprefix GetNextLine/, get_next_line.c get_next_line_utils.c)
PRINTF_SRC = $(addprefix Printf/, ft_print_base.c ft_print_char.c ft_print_hexaMaj.c ft_print_hexMin.c ft_print_pointer.c ft_print_unsigned.c ft_print_str.c ft_printf.c)

NAME = so_long
HEADER		= so_long.h 

MANDATORY = $(addprefix src/, parsing.c main.c map_verifs.c parsing_utils.c floodfill.c mlx_utils.c render.c moves.c clean.c)
LIBFT	= libft/libft.a
PRINTF = Printf/libftprintf.h
GNL = GetNextLine/get_next_line.h
SRCS = $(MANDATORY)
OBJ = $(SRCS:.c=.o)
GNL_OBJ		= $(GNL_SRC:%.c=%.o)
PRINTF_OBJ = $(PRINTF_SRC:%.c=%.o)
OBJS		= $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) 

# .c.o:
# 	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -Iincludes -Imlx -c $< -o $@

#  %.o: %.c $(HEADER)
# 	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME) 

# $(NAME): $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re