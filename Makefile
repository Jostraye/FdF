# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 13:46:48 by jostraye          #+#    #+#              #
#    Updated: 2017/12/13 17:18:44 by jostraye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

FLAGS += -Wall -Wextra -Werror -I
FRMWRK = -framework OpenGL -framework AppKit
LIBS = -lmlx -lft
LX = src/libmlx/
MAP = src/maps/
LT = ./libft/
LTA = libft.a
LXA = libmlx.a
ALLC = *.c
ALLO = *.o

RM = rm -f

MAP0 = $(MAP)test
MAP1 = $(MAP)test1
MAP2 = $(MAP)test2
MAP3 = $(MAP)test3
MAP4 = $(MAP)42.fdf
MAP5 = $(MAP)elem-col.fdf
MAP6 = $(MAP)mars.fdf
MAP7 = $(MAP)t2.fdf
MAP8 = $(MAP)julia.fdf

SRCS = main.c \
       get_matrix.c \
       drawing.c \

all: $(LTA) $(LXA) $(NAME)

$(LXA):
	make -C $(LX)

$(LTA):
	make -C $(LT)

$(NAME):
	gcc $(FLAGS) $(LX) -c $(LT)$(ALLC) $(ALLC)
	gcc $(FLAGS) $(LX) $(ALLO) -L$(LX) -L$(LT) $(LIBS) -o $(NAME) $(FRMWRK)

clean:
	$(RM) $(ALLO) $(LT)$(ALLO) $(LX)$(ALLO)

fclean: clean
	$(RM) $(NAME)

run1:
	./fdf $(MAP1)

run2:
	./fdf $(MAP2)

run3:
	./fdf $(MAP3)

run4:
	./fdf $(MAP4)

run5:
	./fdf $(MAP5)

run6:
	./fdf $(MAP6)

run7:
	./fdf $(MAP7)

run8:
	./fdf $(MAP8)

re: fclean all
