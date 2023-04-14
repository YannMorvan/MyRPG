##
## EPITECH PROJECT, 2023
## libice
## File description:
## MakeList.mk
##

DIR			+= ./engine/engine/
SRC			+= $(addprefix $(lastword $(DIR)),\
				create_engine.c		\
				event_engine.c		\
				update_engine.c		\
				write_framerate.c	\
				set_icon_engine.c	\
				destroy_engine.c	\
				)

DIR			+=	./engine/textures/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				add_texture.c		\
				get_texture.c		\
				destroy_texture.c	\
				)

DIR			+=	./engine/sprites/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				add_sprite.c				\
				add_sprite_and_texture.c	\
				display_sprites.c			\
				destroy_sprite.c			\
				)

DIR			+= ./engine/character/
SRC			+= $(addprefix $(lastword $(DIR)),\
				create_character.c		\
				move_character.c		\
				scale_character.c		\
				center_character.c		\
				set_rect_character.c	\
				destroy_character.c		\
				)

DIR			+= ./engine/collider/
SRC			+= $(addprefix $(lastword $(DIR)),\
				create_collider.c		\
				update_collision.c		\
				collider_set_type.c		\
				)

DIR			+= ./engine/button/
SRC			+= $(addprefix $(lastword $(DIR)),\
				create_button.c			\
				update_buttons.c		\
				destroy_button.c		\
				)

DIR			+= ./engine/window/
SRC			+= $(addprefix $(lastword $(DIR)),\
				clear_window.c			\
				set_splash_screen.c		\
				display_splash_screen.c	\
				destroy_window.c		\
				)

DIR			+= ./engine/mouse/
SRC			+= $(addprefix $(lastword $(DIR)),\
				create_mouse.c		\
				event_mouse.c		\
				update_mouse.c		\
				)

DIR			+= ./engine/scene/
SRC			+= $(addprefix $(lastword $(DIR)),\
				scene_is_open.c		\
				destroy_scene.c		\
				)
