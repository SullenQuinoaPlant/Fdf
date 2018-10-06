NAME = fdf
GIT_REPO = https://github.com/SullenQuinoaPlant/Fdf.git

SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR := $(ROOT)
TEST_DIR := $(ROOT)/tests
AUX_DIR := $(TEST_DIR)/auxilliaries
RELEASE_DIR := $(ROOT)/release

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
