# Target name
#
TARGET = CPPTemplate

# Compiler Setup
#
CC := g++
CFLAGS = -Wall
CXXFLAGS =

# Build Type
# - RELEASE
# - DEBUG
BUILD ?= DEBUG

# SDL2 Setup
# Adding SDL2 library to compilation
SDL2_CONFIG = sdl2-config
SDL2_CFLAGS = $(shell $(SDL2_CONFIG) --cflags)
SDL2_LIBS = $(shell $(SDL2_CONFIG) --libs)

ifeq ($(BUILD), DEBUG)
	CFLAGS += -g -DDEBUG
endif

ifeq ($(BUILD), RELEASE)
	CFLAGS += -s -O2
endif

# Directory Setup
# Setup for obj and src
SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Build all
#
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(SDL2_LIBS)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(SDL2_CFLAGS)

clean:
	rm $(OBJ_DIR)/*.o
	rm $(TARGET)

.PHONY: clean
