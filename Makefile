NAME = so_long
NAME_B = so_long_bonus
CC = gcc 
CFLAGS =-Wall -Wextra -Werror -fsanitize=address,integer,undefined
AR = -lmlx -framework Appkit -framework OpenGl  -fsanitize=address,integer
MAP_H = mandatory/map.h
MAP_H_BONUS = bonus/map.h
SO_LONG = so_long.h
SO_LONG_BONUS = so_long_bonus.h
FILES =	mandatory/map_int.c mandatory/split.c mandatory/ft_error.c mandatory/utils.c mandatory/map_validator.c mandatory/plus.c\
		mandatory/collictbles.c mandatory/moves.c mandatory/map_int.c mandatory/get_next_line.c mandatory/imges.c mandatory/add.c mandatory/so_long.c\
		ft_print/ft_printf.c ft_print/ft_printf_nbrutils.c ft_print/ft_printf_utilities.c

BONUS_FILES = bonus/map_int.c bonus/split.c bonus/ft_error.c bonus/utils.c bonus/map_validator.c bonus/plus.c\
		bonus/collictbles.c bonus/moves.c bonus/get_next_line.c bonus/imges.c bonus/add.c bonus/so_long.c bonus/images_bonus.c\
		./ft_print/ft_printf.c ./ft_print/ft_printf_nbrutils.c ./ft_print/ft_printf_utilities.c bonus/animation.c\
		bonus/itoa.c bonus/collictbles_animation.c

OBJS =$(FILES:.c=.o)

OBJS_BONUS =$(BONUS_FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(AR) -o $(NAME) $^

bonus : $(NAME_B)

$(NAME_B) : $(OBJS_BONUS)
	$(CC) $(AR) -o $(NAME_B) $^

%.o :%.c $(SO_LONG) $(SO_LONG_BONUS) $(MAP_H) $(MAP_H_BONUS)
	$(CC)  $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all
.PHONY : make clean fclean all