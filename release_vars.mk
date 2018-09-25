
NAME = myrbtree
LIBNAME = lib$(NAME)

ROOT = .
SRC_DIR	:= $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)
LIBS_I := $(INC_DIR)
OUT_DIR_LIB := $(ROOT)
OUT_DIR_H := $(LIBS_I)

OBJS = $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR)
endif
CFLAGS += $(CFLAGS_MORE)
