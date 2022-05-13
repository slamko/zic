CC=gcc
TARGET=test_zic
LIBS=-Ilib

all: $(TARGET)

$(TARGET): test.c
	$(CC) -g $(LIBS) $^ -o $@

.SILENT: test

test: $(TARGET)
	./$(TARGET) &
	echo " "
