.PHONY : def
def : targets
	$(MAKE) all


############
#VARIABLES :
ifndef ROOT
 ROOT := .
endif
include $(ROOT)/make_vars.mk


#######
#CORE :
include $(ROOT)/core.mk


########################
#TARGETS & DEPENDENCIES:
include $(SRC_DIR)/Makefile

#######
#LIBS :
include $(LIB_DIR)/Makefile

########
#TESTS :
include $(TEST_DIR)/Makefile
include $(AUX_DIR)/Makefile


##########
#RELEASE :
.PHONY : release
release : $(RELEASE_DIR)

.PHONY : $(RELEASE_DIR)
$(RELEASE_DIR) :
	if [ -d $@ ];\
	then rm -rf $(RELEASE_DIR)/;\
	fi
	git clone \
		--single-branch \
		-b release \
		$(GIT_REPO) \
		$@
	cd $@ && git rm -rf *
	cp auteur $@/
	mkdir $@/sources
	cp $(SRCS) $@/sources
	mkdir $@/includes
	cp $(INCS) $@/includes
	cp $(patsubst %,$(LIBS_I)/%.h,$(DEPENDENCIES)) $@/includes
	cat $(ROOT)/targets.mk $(ROOT)/release_vars.mk $(ROOT)/core.mk >\
		$@/Makefile
	cd $@ && \
		git add * && \
		git commit -m make_release && \
		git push origin release
