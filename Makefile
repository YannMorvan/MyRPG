##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

NAME		:=	my_rpg

LIB			:=	./lib/

DIR_SRC		:=	./src/

DIR			:=	$(DIR_SRC)
SRC			:=	$(addprefix $(DIR),\
				main.c				\
				)

DIR			+=	$(addprefix $(DIR_SRC), ./init/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_hud.c			\
				create_game.c			\
				create_player.c			\
				create_pause_button.c	\
				add_monster.c			\
				)

DIR			+=	$(addprefix $(DIR_SRC), ./event/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				event_game.c			\
				event_player.c			\
				)

DIR			+=	$(addprefix $(DIR_SRC), ./update/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				update_game.c			\
				update_player.c			\
				update_monsters.c		\
				)

DIR			+=	$(addprefix $(DIR_SRC), ./display/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				display_game.c			\
				)

DIR			+=	$(addprefix $(DIR_SRC), ./destroy/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				destroy_game.c			\
				destroy_player.c		\
				destroy_monster.c		\
				)

DIR_TEST	:=	./tests/
SRC_TEST	:=	$(addprefix $(DIR_TEST),\
				)

ROOT_OBJ	:=	./.obj/
DIR_OBJ		:=	$(addprefix $(ROOT_OBJ), $(DIR))
OBJ			:=	$(patsubst %.c, $(ROOT_OBJ)%.o, $(SRC))

UNIT_TEST	:=	./unit_test

RM			:=	rm -rf
MAKE		:=	make -sC$(LIB) -j

CC			:=	gcc
CFLAGS		:=	-I./include/ -Wall -Wextra
LDFLAGS		:=	-L$(LIB)
LDLIBS		:=	-lice -lm -lcsfml-graphics -lcsfml-system

all:				$(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)\
	&& printf "\033[93m[CREATED]\033[0m %s\n" $(DIR_OBJ)\
	|| printf "\033[31m[ERROR]\033[0m %s\n" $(DIR_OBJ)

$(ROOT_OBJ)%.o:		%.c
	@$(CC) $(CFLAGS) -c $< -o $@\
	&& printf "\033[32m[OK]\033[0m %s\n" $<\
	|| printf "\033[31m[KO]\033[0m %s\n" $<

$(NAME):			$(OBJ)
	@$(MAKE)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)\
	&& printf "\033[32m[SUCCESS]\033[0m %s\n" $@\
	|| printf "\033[31m[ERROR]\033[0m %s\n" $@

$(UNIT_TEST):
	@$(MAKE) $(UNIT_TEST)

tests_run:
	@$(MAKE) $@

tests_clean:
	@$(MAKE) $@

lib_all:
	@$(MAKE) all

lib_re:
	@$(MAKE) re

lib_debug:
	@$(MAKE) debug

debug:				CFLAGS += -g
debug:				lib_debug re

clean:
	@$(MAKE) $@
	@[ -d $(ROOT_OBJ) ]\
	&& $(RM) $(ROOT_OBJ)\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(ROOT_OBJ) || true

fclean:				clean tests_clean
	@$(MAKE) $@
	@[ -f $(NAME) ]\
	&& $(RM) $(NAME)\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(NAME) || true

re:					fclean all

.PHONY:				all clean fclean re $(NAME)

.SILENT:			all test_run test_coverage debug clean fclean re
