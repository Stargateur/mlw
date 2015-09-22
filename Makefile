##
## Makefile for wayland in /home/plasko_a/programation/epitech/mlw
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Mon Nov  3 12:29:58 2014 Antoine Plaskowski
## Last update Tue Sep 22 22:24:02 2015 Antoine Plaskowski
##

NAME			=	wayland

CC			=	gcc

RM			=	rm -f

MKDIR			=	mkdir -p

RMDIR			=	rmdir --ignore-fail-on-non-empty

ECHO			=	/bin/echo

DEBUG			=	no

LEVEL			=	3

LIB			=	-l wayland-client

INCLUDE			=	-I include/

CFLAGS			=	-Wall -Wextra -O$(LEVEL)
CFLAGS			+=	-pedantic
CFLAGS			+=	$(INCLUDE)
CFLAGS			+=	-fdiagnostics-color
#CFLAGS			+=	-D _GNU_SOURCE

ifeq ($(CC), clang)
CFLAGS			+=	-Weverything
endif

ifneq ($(DEBUG), no)
CFLAGS			+=	-g
endif

LDFLAGS			=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS			+=	-s
endif

DFLAGS			=	-Y -w80 $(INCLUDE)

SRC			=

include				source.mk

OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean			:
				$(RM) $(OBJ)

fclean			:
				$(RM) $(OBJ)
				$(RM) $(NAME)

re			:	fclean
				${MAKE} -C . all

depend			:
				makedepend $(SRC) $(DFLAGS)

%.o			:	%.c
				$(CC) -c $< -o $@ $(CFLAGS)

%.s			:	%.c
				$(CC) -S $< -o $@ $(CFLAGS)

.PHONY			:	all clean fclean re %.o %.s

.SUFFIXES		:	.o.c .s.c

# DO NOT DELETE
