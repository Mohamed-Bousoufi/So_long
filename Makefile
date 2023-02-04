NAME = so_long
CC = gcc 
CFLAGS =-Wall -Wextra -Werror
AR = cc -lmlx -framework Appkit -framework OpenGl
MAP_H = map/map.h
SO_LONG = so_long.h
FILES =	map_int.c split.c ft_error.c utils.c map_validator.c plus.c\
		collictbles.c moves.c map_int.c get_next_line.c imges.c add.c\
		ft_print/ft_printf.c ft_print/ft_printf_nbrutils.c ft_print/ft_printf_utilities.c

OBJS =$(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) -o $(NAME) $^ 

%.o :%.c $(MAP_H) $(SO_LONG)
	$(CC)  $(CFLAGS) -c $< 
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all