CC=gcc
CFLAGS=-ggdb
TARGET=test_zic
LIBS=-Ilib
SRC_TARGET=test/mini.c

include tests/Makefile

example-std:
	$(CC) $(LIBS) examples/mini.c -o zic_example_std

example-full-api:
	$(CC) $(LIBS) examples/full.c -o zic_example_full_api
