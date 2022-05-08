CC=gcc
TARGET=test

all: $(TARGET)

$(TARGET): test.c
	$(CC) -g $^ -o $@

.SILENT: run

run: $(TARGET)
	./$(TARGET) &
	echo " "
