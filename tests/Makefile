ifndef ROOT
 ROOT := ..
 include $(ROOT)/Makefile
endif

TEST_SRCS := $(wildcard $(TEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CFLAGS_TEST = -fno-builtin -g
CFLAGS_TEST += $(CFLAGS_MORE)

TEST_DEPENDENCIES = libaux libcmocka_shared


.PHONY : tests_all
tests_all :\
$(TOOLS)_ld\
build_test_dependencies\
clean-tests\
build_tests\
run_tests


############
#BUILD TESTS

.PHONY : build_test_dependencies
build_test_dependencies : $(TEST_DEPENDENCIES)

.PHONY : libcmocka_shared
libcmocka_shared :
	$(MAKE) -C $(TEST_DIR)/cmocka

.PHONY : build_tests
build_tests\
:\
set_test_flags def\
$(TEST_OBJS)

.PHONY : set_test_flags
set_test_flags :
	$(eval CFLAGS += $(CFLAGS_TEST))

.PHONY : test_prerequisites
test_prerequisites : cmocka

.PHONY : cmocka
cmocka : 
	@if $(CC_TEST) $(CFLAGS_TEST)\
		-I $(LIBS_I) -L $(LIBS_L)\
	 	$(TEST_DIR)/cmocka/check_install.c\
		-lcmocka -o test.o\
		-Wl,-rpath=$(LIBS_L)\
		&& ./test.o .;\
	then\
		echo "cmocka installed";\
	else\
		echo "cmocka not installed";\
	fi
	-@rm ./test.o


$(TEST_DIR)/%.test.o\
:\
$(TEST_DIR)/%.test.c\
$(LIBS_L)/$(LIBNAME).a
	$(CC_TEST) $(CFLAGS_TEST)\
		-I $(LIBS_I) -I $(SRC_DIR) -I $(INC_DIR)\
		$<\
		-L $(LIBS_L)\
		$(patsubst lib%,-l%,$(TEST_DEPENDENCIES))\
		-l$(NAME)\
		$(patsubst lib%,-l%,$(DEPENDENCIES))\
		-o $@\
		-Wl,-rpath=$(LIBS_L)\

.PHONY : maintest
maintest : $(TEST_DIR)/main.test.o

$(TEST_DIR)/main.test.o\
:\
$(TEST_DIR)/main.test.c\
$(LIBS_L)/$(LIBNAME).a
	$(CC_TEST) $(CFLAGS_TEST)\
		-I $(LIBS_I) -I $(SRC_DIR) -I $(INC_DIR)\
		$<\
		-L $(LIBS_L)\
		-laux\
		-l$(NAME)\
		-lft\
		-o $@\

############
#RUN TESTS :

.PHONY : tests
tests : list_tests test_prerequisites build_tests run_tests

.PHONY : run_tests
run_tests : $(EXECUTION_STAMPS)

%.execution.stamp : %.o
	-./$*.o "$(TEST_DIR)" \
	&& touch $@



###############
#MISCELLANEOUS:
.PHONY : clean-tests
clean-tests :
	-rm $(TEST_DIR)/*.o
	-rm $(TEST_DIR)/*.stamp

.PHONY : list_tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)

.PHONY : mac_ld
mac_ld :
	sed -i "" -e's@-Wl,-rpath=@-Wl,-rpath,@' $(TEST_DIR)/Makefile

.PHONY : gnu_ld
gnu_ld :
	sed -i -e's@-Wl,-rpath,@-Wl,-rpath=@' $(TEST_DIR)/Makefile
