# Compiler and flags
CC = g++
FLAGS = -g -c -Wall
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lX11

# Source files and object files
OBJS = use/useinput.o use/camera.o use/compiler.o use/main.o use/player.o use/userInputHandler.cpp
SOURCE = use/useinput.cpp use/camera.cpp use/compiler.cpp use/main.cpp use/player.cpp use/userInputHandler.cpp
HEADER = use/useinput.h use/compiler.h use/player.h use/userInputHandler.h
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
