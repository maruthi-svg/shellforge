CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

TARGET = shellforge

SOURCES = src/main.c \
          src/history.c \
          src/token.c \
          src/lexer.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -lreadline -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean
