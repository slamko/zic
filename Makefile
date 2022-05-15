CC=gcc
TARGET=test_zic
LIBS=-Ilib

all: $(TARGET)

.PHONY: clean test_zic

$(TARGET): test/test.c lib/*.h
	$(CC) -ggdb $(LIBS) $< -o $@

.SILENT: test

test: $(TARGET)
	./$(TARGET) &
	echo " "


clean:
	$(RM) $(TARGET) *.o
