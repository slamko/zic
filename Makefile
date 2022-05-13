CC=gcc
TARGET=test_zic
LIBS=-Ilib

all: $(TARGET)

$(TARGET): test/test.c
	$(CC) -ggdb $(LIBS) $^ -o $@

.SILENT: test

test: $(TARGET)
	./$(TARGET) &
	echo " "
