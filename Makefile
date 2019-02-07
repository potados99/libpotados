# Makefile template for shared library

CC = gcc # C compiler
CFLAGS = -fPIC -Wall -Wextra -O2 -g # C flags
LDFLAGS = -shared # linking flags
RM = rm -f  # rm command

TARGET_LIB = libpotados.so.1.0.0 # target lib
HEADER_CHK = .include

INCLUDE_DIR = /usr/local/include
LIB_DIR = /usr/local/lib

HEADS = pio.h pdbg.h putil.h ptype.h
SRCS = pio.c # source files
OBJS = $(SRCS:.c=.o)

all: $(TARGET_LIB) $(HEADER_CHK)

$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	cp $(TARGET_LIB) $(LIB_DIR)

$(HEADER_CHK): $(HEADS)
	cp $(HEADS) $(INCLUDE_DIR)
	touch $(HEADER_CHK)

clean:
	$(RM) $(TARGET_LIB) $(OBJS) $(HEADER_CHK) $(HEADER_CHK) $(addprefix $(INCLUDE_DIR)/, $(HEADS)) $(LIB_DIR)/$(TARGET_LIB)
