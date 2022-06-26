CC=gcc
BIND=bin
BUILDD=build
BDIRS=$(BIND) $(BUILDD)

TESTS:=$(wildcard *.c)
OBJS:=$(TESTS:%.c=$(BUILDD)/%.o)
BINS:=$(TESTS:%.c=$(BIND)/%)

all: test

test: $(BDIRS) $(BINS)
	for test in $(BINS); do ./$$test ; done

$(BDIRS):
	mkdir -p $@

$(BIND)/%: $(BUILDD)/%.o
	$(CC) $< -o $@  -lcriterion

$(BUILDD)/%.o: %.c
	$(CC) -c $< -o $@ -DMINI_ZIC -I../lib
