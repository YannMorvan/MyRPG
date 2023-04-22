##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

NAME		:=	my_rpg

LIB			:=	./lib/

DIR_SRC		:=	src/
DIR_SCENES	:=	$(addprefix $(DIR_SRC), scenes/)

DIR			:=	$(DIR_SRC)
SRC			:=	$(addprefix $(DIR),\
				main.c				\
				)

DIR			+=	$(addprefix $(DIR_SRC), rpg/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_rpg.c			\
				destroy_rpg.c			\
				)

DIR			+=	$(addprefix $(DIR_SRC), parsing/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				read_file.c				\
				file_parse.c			\
				get_parse.c				\
				destroy_parse.c			\
				)

DIR			+=	$(addprefix $(DIR_SRC), update/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				update_button_texture.c		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), home/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				home.c				\
				create_home.c		\
				event_home.c		\
				update_home.c		\
				display_home.c		\
				destroy_home.c		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), home/menu/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				load_icon.c			\
				load_background.c	\
				get_window_size.c	\
				)

DIR			+=	$(addprefix $(DIR_SCENES), home/menu/buttons/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_buttons.c			\
				set_button.c				\
				create_start_button.c		\
				create_load_button.c		\
				create_options_button.c		\
				create_exit_button.c		\
				create_size_button.c		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				game.c				\
				create_game.c		\
				event_game.c		\
				update_game.c		\
				display_game.c		\
				destroy_game.c		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/map/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_map.c	\
				load_map.c		\
				clear_map.c		\
				destroy_map.c	\
				set_wall.c		\
				set_floor.c		\
				set_ladder.c	\
				set_player.c	\
				set_monster.c	\
				set_npc.c		\
				get_tile_pos.c	\
				)

DIR			+= 	$(addprefix $(DIR_SCENES), game/attacks/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				update_attacks.c	\
				destroy_attacks.c	\
				destroy_attack.c	\
				create_attacks.c	\
				get_angle.c 		\
				get_middle.c 		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/attacks/spell/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_spell.c		\
				create_sword_spell.c	\
				create_heal.c 		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/player/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_player.c		\
				event_player.c		\
				update_player.c		\
				destroy_player.c	\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/npcs/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				update_npcs.c		\
				destroy_npcs.c		\
				destroy_npc.c		\
				create_quest.c		\
				update_quest.c		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/npcs/devil/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_devil.c		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/monsters/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				update_monsters.c	\
				destroy_monsters.c	\
				destroy_monster.c	\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/monsters/slime/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_slime.c		\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/menu/buttons/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_pause_button.c	\
				)

DIR			+=	$(addprefix $(DIR_SCENES), game/hud/)
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_hud.c	\
				)

DIR_TEST	:=	./tests/
SRC_TEST	:=	$(addprefix $(DIR_TEST),\
				)

DIR_BUILD	:=	./build/

ROOT_OBJ	:=	$(addprefix $(DIR_BUILD), obj/)
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
	@[ -d $(DIR_BUILD) ]\
	&& $(RM) $(DIR_BUILD)\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(DIR_BUILD) || true

fclean:				clean
	@$(MAKE) $@
	@[ -f $(NAME) ]\
	&& $(RM) $(NAME)\
	&& printf "\033[31m[DELETED]\033[0m %s\n" $(NAME) || true

re:					fclean all

.PHONY:				all clean fclean re $(NAME)

.SILENT:			all test_run test_coverage debug clean fclean re
