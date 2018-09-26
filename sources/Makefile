ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif

.PHONY : targets
targets :
	@echo "TARGETS := \\" > $(ROOT)/targets.mk
	@find . -name "*.c"\
	|sed 's@.*/\([a-z0-9][a-z0-9_]*\)\.c@	\1 \\@' \
	|sed '$$s@\(.*\) \\@\1@' >> $(ROOT)/targets.mk
