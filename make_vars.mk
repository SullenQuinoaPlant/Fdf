NAME = myrbtree
LIBNAME = lib$(NAME)
GIT_REPO = https://github.com/SullenQuinoaPlant/.git

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)
TEST_DIR := $(ROOT)/tests
AUX_DIR := $(TEST_DIR)/auxilliaries
RELEASE_DIR := $(ROOT)/release_$(NAME)

include $(ROOT)/targets.mk
SRCS = $(patsubst %,$(SRC_DIR)/%.c,$(TARGETS))
OBJS = $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))
INCS = $(INC_DIR)/*.h

DEPENDENCIES = libft

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBS_I)
endif
CFLAGS += $(CFLAGS_MORE)
