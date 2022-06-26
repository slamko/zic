CC=gcc
BIND=bin
BUILDD=build

TESTS:=$(wildcard *.c)
OBJS:=$(TESTS:%.c=$(BUILDD)/%.o)
BINS:=$(TESTS:%.c=$(BIND)/%)

all: test

test: $(BINS)
	for test in $(BINS); do ./$$test ; done

$(BIND)/%: $(BUILDD)/%.o
	$(CC) $< -o $@  -lcriterion

$(BUILDD)/%.o: %.c
	$(CC) -c $< -o $@ -DMINI_ZIC -I../lib
