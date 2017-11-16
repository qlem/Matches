##
## Makefile for Allum1 in /home/dommer_c/rendu/CPE_2015_Allum1
## 
## Made by dommer_c
## Login   <dommer_c@epitech.net>
## 
## Started on  Wed Feb 17 16:08:35 2016 dommer_c
## Last update Thu Nov 16 22:03:22 2017 qlem
##

CC=	gcc

RM=	rm -f

NAME=	matches

CFLAGS=	-Wextra -Wall -Werror -W -ansi -pedantic

SRC=	matches.c	\
	create_tab.c	\
	get_next_line.c	\
	error_manag.c	\
	ia.c		\
	ia_special.c	\
	other.c

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) ./include/*~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
