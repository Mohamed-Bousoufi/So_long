NAME = so_long
CC = gcc 
CFLAGS =-Wall -Wextra -Werror  #-fsanitize=address,integer,undefined
AR = cc -lmlx -framework Appkit -framework OpenGl #-fsanitize=address,integer,undefined
MAP_H = map/map.h
SO_LONG = so_long.h
FILES =	map_int.c split.c ft_error.c utils.c map_validator.c\
		collictbles.c moves.c map_int.c get_next_line.c\
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