ifndef ROOT
	ROOT = ../..
	include $(ROOT)/Makefile
endif

AUX_TARGETS =

AUX_SRCS := $(patsubst %,$(AUX_DIR)/%.c,$(AUX_TARGETS))
AUX_OBJS := $(patsubst %,$(AUX_DIR)/%.o,$(AUX_TARGETS))

.PHONY : libaux
libaux : $(LIBS_L)/libaux.a 

$(LIBS_L)/libaux.a : $(AUX_OBJS)
	ar -rcs $@ $^
	cp $(AUX_DIR)/auxilliaries.h $(LIBS_I)/libaux.h

$(AUX_DIR)/%.o : $(AUX_DIR)/%.c
	$(CC)\
		$(CFLAGS_TEST)\
		-I $(LIBS_I) -I $(SRC_DIR) -I $(INC_DIR)\
		-c\
		$<\
		-L $(LIBS_L)\
		-lft\
		-o $@\

.PHONY : clean-auxobjs
clean-auxobjs :
	-rm $(AUX_OBJS)

.PHONY : re_libaux
re_libaux : clean-libaux clean-auxobjs libaux
