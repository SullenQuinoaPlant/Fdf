ifndef ROOT
 ROOT = ..
 include $(ROOT)/Makefile
endif


.PHONY : build_dependencies
build_dependencies : $(DEPENDENCIES)
	@echo "$(DEPENDENCIES)"

.PHONY : clean-dependencies
clean-dependencies : $(patsubst %,clean-%,$(DEPENDENCIES))

.PHONY : re_dependencies
re_dependencies : clean-dependencies build_dependencies

define BUILD_LIB
	$(MAKE) -C $(LIB_DIR)/$@/ 
	cp $(LIB_DIR)/$@/$@.a $(LIBS_L)
	cp $(LIB_DIR)/$@/includes/$@.h $(LIBS_I)
endef

libft :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/Libft.git \
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)

libgetnextline :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/get_next_line.git \
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)


.PHONY : clean-lib*
clean-lib% :
	-rm -rf $(LIB_DIR)/lib$*
	-rm $(LIBS_I)/lib$*.h
	-rm $(LIBS_L)/lib$*.a

.PHONY : re_lib*
re_lib% : clean-lib% lib%
	@:
