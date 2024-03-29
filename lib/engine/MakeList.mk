##
## EPITECH PROJECT, 2023
## libice
## File description:
## MakeList.mk
##

DIR			+= engine/engine/
SRC			+= $(addprefix $(lastword $(DIR)),\
				create_engine.c		\
				event_engine.c		\
				update_engine.c		\
				write_framerate.c	\
				set_icon_engine.c	\
				destroy_engine.c	\
				)

DIR			+=	engine/textures/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				add_texture.c		\
				get_texture.c		\
				destroy_texture.c	\
				)

DIR			+=	engine/sprites/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				add_sprite.c				\
				add_sprite_and_texture.c	\
				display_sprites.c			\
				destroy_sprite.c			\
				)

DIR			+=	engine/character/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_character.c		\
				move_character.c		\
				move_delta_character.c	\
				center_character.c		\
				set_pos_character.c		\
				set_rect_character.c	\
				set_scale_character.c	\
				destroy_character.c		\
				)

DIR			+=	engine/collider/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_collider.c		\
				update_collision.c		\
				collider_set_type.c		\
				debug_collider.c		\
				)

DIR			+=	engine/button/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_button.c			\
				update_buttons.c		\
				destroy_button.c		\
				)

DIR			+=	engine/window/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				clear_window.c			\
				set_splash_screen.c		\
				display_splash_screen.c	\
				destroy_window.c		\
				)

DIR			+=	engine/mouse/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_mouse.c		\
				event_mouse.c		\
				update_mouse.c		\
				)

DIR			+=	engine/scene/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				scene_is_open.c		\
				destroy_scene.c		\
				)

DIR			+=	engine/font/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_font.c		\
				destroy_font.c		\
				)

DIR			+=	engine/text/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_text.c		\
				get_text.c			\
				display_texts.c		\
				destroy_text.c		\
				)

DIR			+=	engine/music/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_music.c		\
				set_volume_music.c	\
				destroy_music.c		\
				)

DIR			+=	engine/sound/
SRC			+=	$(addprefix $(lastword $(DIR)),\
				create_sound.c		\
				create_sounds.c		\
				get_sound.c			\
				play_sound.c		\
				set_volume_sounds.c	\
				destroy_sound.c		\
				destroy_sounds.c	\
				)
