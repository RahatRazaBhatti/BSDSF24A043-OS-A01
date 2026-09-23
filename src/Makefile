# Feature 4: build static (.a) and dynamic (.so) libraries and clients

CC = gcc
CFLAGS = -Wall -Wextra -I../include

OBJDIR = ../obj
PICDIR = ../obj/pic
BINDIR = ../bin
LIBDIR = ../lib

HEADERS = $(wildcard ../include/*.h)

LIB_SRC = mystrfunctions.c myfilefunctions.c
LIB_OBJ = $(LIB_SRC:%.c=$(OBJDIR)/%.o)
PIC_OBJ = $(LIB_SRC:%.c=$(PICDIR)/%.o)

MAIN_OBJ = $(OBJDIR)/main.o
ALL_OBJ = $(LIB_OBJ) $(MAIN_OBJ)

TARGET = $(BINDIR)/client
STATIC_LIB = $(LIBDIR)/libmyutils.a
SHARED_LIB = $(LIBDIR)/libmyutils.so
TARGET_STATIC = $(BINDIR)/client_static
TARGET_DYNAMIC = $(BINDIR)/client_dynamic

all: $(TARGET) $(TARGET_STATIC) $(TARGET_DYNAMIC)

$(TARGET): $(ALL_OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(ALL_OBJ) -o $@

# ---- static ----
$(STATIC_LIB): $(LIB_OBJ)
	@mkdir -p $(LIBDIR)
	ar rcs $@ $^
	ranlib $@

$(TARGET_STATIC): $(MAIN_OBJ) $(STATIC_LIB)
	@mkdir -p $(BINDIR)
	$(CC) -static $(MAIN_OBJ) -L$(LIBDIR) -lmyutils -o $@

# ---- dynamic ----
$(PICDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(PICDIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(SHARED_LIB): $(PIC_OBJ)
	@mkdir -p $(LIBDIR)
	$(CC) -shared $^ -o $@

$(TARGET_DYNAMIC): $(MAIN_OBJ) $(SHARED_LIB)
	@mkdir -p $(BINDIR)
	$(CC) $(MAIN_OBJ) -L$(LIBDIR) -lmyutils -o $@

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(PICDIR) $(BINDIR)/client* $(LIBDIR)/libmyutils.*

.PHONY: all clean
