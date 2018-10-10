all : $(OUT_DIR)/$(NAME)

$(OUT_DIR)/$(NAME) : $(OBJS)
	$(CC) -o $@ $^\
		-L $(LIBS_L)\
		$(patsubst lib%,-l%,$(DEPENDENCIES)

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
