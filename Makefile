NAME = so_long
CC = gcc 
CFLAGS =-Wall -Wextra -Werror #-fsanitize=address,integer,undefined
AR = cc -lmlx -framework Appkit -framework OpenGl  #-fsanitize=address,integer
MAP_H = map/map.h
SO_LONG = so_long.h
FILES =	mandatory/map_int.c mandatory/split.c mandatory/ft_error.c mandatory/utils.c mandatory/map_validator.c mandatory/plus.c\
		mandatory/collictbles.c mandatory/moves.c mandatory/map_int.c mandatory/get_next_line.c mandatory/imges.c mandatory/add.c mandatory/so_long.c\
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