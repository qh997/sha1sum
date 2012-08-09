OBJECT := sha1sum.o
OBJECT += sha1.o

ifneq ($(CC), gcc)
CC := gcc
endif
CFLAGS := -std=gnu99

.PHONY: all clean

all: clean sha1sum

clean:
	-rm $(OBJECT) sha1sum

sha1sum: $(OBJECT)
	@echo
	@echo 'make sha1sum'
	$(CC) $(CFLAGS) $^ -o $@
	@echo
