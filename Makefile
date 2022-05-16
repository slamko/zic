CC=gcc
CFLAGS=-ggdb
TARGET=test_zic
LIBS=-Ilib
SRC_TARGET=test/mini.c

all: $(TARGET)

.PHONY: clean test_zic

$(TARGET): $(SRC_TARGET) lib/*.h
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

mini: CFLAGS+= -DMINI_ZIC
mini: clean 
mini: SRC_TARGET=test/mini.c
mini: $(TARGET)

.SILENT: test

test: $(TARGET)
	./$(TARGET) &
	echo " "

clean:
	$(RM) $(TARGET) *.o
