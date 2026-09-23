# Feature 3: build static library libmyutils.a and link main against it

CC = gcc
CFLAGS = -Wall -Wextra -I../include

OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib

HEADERS = $(wildcard ../include/*.h)

LIB_SRC = mystrfunctions.c myfilefunctions.c
LIB_OBJ = $(LIB_SRC:%.c=$(OBJDIR)/%.o)

MAIN_OBJ = $(OBJDIR)/main.o
ALL_OBJ = $(LIB_OBJ) $(MAIN_OBJ)

TARGET = $(BINDIR)/client
STATIC_LIB = $(LIBDIR)/libmyutils.a
TARGET_STATIC = $(BINDIR)/client_static

all: $(TARGET) $(TARGET_STATIC)

$(TARGET): $(ALL_OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(ALL_OBJ) -o $@

$(STATIC_LIB): $(LIB_OBJ)
	@mkdir -p $(LIBDIR)
	ar rcs $@ $^
	ranlib $@

$(TARGET_STATIC): $(MAIN_OBJ) $(STATIC_LIB)
	@mkdir -p $(BINDIR)
	$(CC) -static $(MAIN_OBJ) -L$(LIBDIR) -lmyutils -o $@

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(OBJDIR)/pic $(BINDIR)/client* $(LIBDIR)/libmyutils.*

.PHONY: all clean
