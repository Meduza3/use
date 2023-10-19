# Compiler and flags
CC = g++
FLAGS = -g -c -Wall
LFLAGS = 

# Source files and object files
OBJS = button.o camera.o compiler.o main.o player.o
SOURCE = button.cpp camera.cpp compiler.cpp main.cpp player.cpp
HEADER = button.h compiler.h player.h
OUT = main

# Libraries
LDLIBS = 

# Default target
all: $(OUT)

# Linking rules
$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) $(LDLIBS)

# Compilation rules
%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -o $@ $<

# Clean rule
clean:
	rm -f $(OBJS) $(OUT)
