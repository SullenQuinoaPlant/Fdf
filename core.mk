.PHONY : all
all : $(OUT_DIR)/$(NAME)

$(OUT_DIR)/$(NAME)\
:\
$(OBJS)\
$(patsubst %,$(LIBS_L)/%.a,$(DEPENDENCIES))\
$(FORCE_RELINK)
	$(CC) -o $@ $(OBJS)\
		-L $(LIBS_L)\
		-lm\
		$(MLX_AND_CO)\
		$(patsubst lib%,-l%,$(DEPENDENCIES))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-o $@ -c $<


.PHONY : re fclean clean all
clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
