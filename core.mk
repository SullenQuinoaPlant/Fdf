all : header library

.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h

$(OUT_DIR_H)/$(LIBNAME).h :
	sed -e'4s@\($(NAME).h\)   @lib\1@'\
		-e'13,14s@M@LIB&@'\
		$(INC_DIR)/$(NAME).h > $@

.PHONY : library
library : $(OUT_DIR_LIB)/$(LIBNAME).a

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJS)
	-ar rcs $@ $^

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
