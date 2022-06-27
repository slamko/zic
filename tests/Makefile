CC=gcc
BIND=bin
BUILDD=build
BASETD=base
FULLTD=full
BDIRS=$(BIND) $(BIND)/$(BASETD) $(BIND)/$(FULLTD) $(BUILDD) $(BUILDD)/$(BASETD) $(BUILDD)/$(FULLTD)

BASE_TESTS:=$(wildcard $(BASETD)/*.c)
FULL_TESTS:=$(wildcard $(FULLTD)/*.c)
TESTS:=$(BASE_TESTS) $(FULL_TESTS)
OBJS:=$(BASE_TESTS:$(BASETD)/%.c=$(BUILDD)/$(BASETD)/%.o)
OBJS+=$(FULL_TESTS:$(FULLTD)/%.c=$(BUILDD)/$(FULLTD)/%.o)
BASE_BINS:=$(BASE_TESTS:$(BASETD)/%.c=$(BIND)/$(BASETD)/%)
FULL_BINS:=$(FULL_TESTS:$(FULLTD)/%.c=$(BIND)/$(FULLTD)/%)
BINS=$(BASE_BINS) $(FULL_BINS)

all: test

.SILENT: test

test: $(BDIRS) $(BINS)
	echo "base api tests:"
	for test in $(BASE_BINS); do ./$$test ; done

	echo "full api tests:"
	for test in $(FULL_BINS); do ./$$test ; done

$(BDIRS):
	mkdir -p $@

$(BIND)/%: $(BUILDD)/%.o
	$(CC) $< -o $@  -lcriterion

$(BUILDD)/$(BASETD)/%.o: $(BASETD)/%.c
	$(CC) -c $< -DMINI_ZIC -o $@ -I../lib

$(BUILDD)/$(FULLTD)/%.o: $(FULLTD)/%.c
	$(CC) -c $< -o $@ -I../lib
