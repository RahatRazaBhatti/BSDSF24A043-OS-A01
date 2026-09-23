# Feature 2: compile all .c files directly and link into one executable

CC = gcc
CFLAGS = -Wall -Wextra -I../include

OBJDIR = ../obj
BINDIR = ../bin

HEADERS = $(wildcard ../include/*.h)

SOURCES = mystrfunctions.c myfilefunctions.c main.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

TARGET = $(BINDIR)/client

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJECTS) -o $@

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/client

.PHONY: all clean
