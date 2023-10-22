# Compiler and flags
CC = g++
FLAGS = -g -c -Wall
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files and object files
OBJS = useinput.o camera.o compiler.o main.o player.o
SOURCE = useinput.cpp camera.cpp compiler.cpp main.cpp player.cpp
HEADER = useinput.h compiler.h player.h
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
