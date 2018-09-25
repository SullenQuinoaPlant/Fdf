ifndef ROOT
	ROOT = ../..
	include $(ROOT)/make_vars.mk
endif

BUILD_DIR = cmocka_build
SOURCE_DIR = cmocka_source

cmocka : $(BUILD_DIR) $(SOURCE_DIR) build install

.PHONY : build
build :
	cd $(BUILD_DIR) && cmake ../$(SOURCE_DIR) && make;

.PHONY : install
install :
	cp $(SOURCE_DIR)/include/cmocka.h $(LIBS_I)/
	cp $(BUILD_DIR)/src/libcmocka* $(LIBS_L)/
	touch $(LIB_DIR)/libcmocka_shared

$(BUILD_DIR) :
	if ! [ -d $(BUILD_DIR) ];\
	then mkdir $(BUILD_DIR);\
	fi

$(SOURCE_DIR) :
	if [ -d $(SOURCE_DIR) ];\
	then rm -rf $(SOURCE_DIR);\
	fi
	git clone \
		--depth 1 \
		git://git.cryptomilk.org/projects/cmocka.git \
		$(SOURCE_DIR)
